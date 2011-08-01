// ASMExtract.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "ASMExtract.h"
#include "CSldWorks.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 唯一的应用程序对象
CWinApp theApp;

VARIANT_BOOL retVal = VARIANT_FALSE;
HRESULT hres = NOERROR;

//Function prototypes
void OpenAssembly(ISldWorks* swApp, IModelDoc2** swModel);
void TraverseFeatureManagerDesignTree(IModelDoc2* swModel, IComponent2** swComponent);
void SuppressSelectedComponent(IComponent2* swComponent, ISldWorks* swApp);
void ResolveSelectedComponent(IComponent2* swComponent, ISldWorks* swApp);
void ExplodeAssembly(IModelDoc2* swModel, IAssemblyDoc** swAssemblyDoc);
void CollapseAssembly(IModelDoc2* swModel, IAssemblyDoc* swAssemblyDoc);
void CreateDrawingOfAssembly(ISldWorks* swApp, IModelDoc2* swModel);
void CloseDocuments(ISldWorks* swApp);
void GetModelAssembly(ISldWorks* m_pSldWorks);
int TraverseChildren(long RecurseLevel, CString* MyString, IComponent2* pComponent, ISldWorks* m_pSldWorks);
void Do();
void SelectionComponent(ISldWorks * m_pSldWorks);
void UserGetSelectedObjectsComponent3();


using namespace std;

//程序入口
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[]) {
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL) {
		// 初始化 MFC 并在失败时显示错误
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0)) {
			// TODO: 更改错误代码以符合您的需要
			cout << "错误: MFC 初始化失败" << endl;
			nRetCode = 1;
		} else {
			Do();
		}
	} else {
		// TODO: 更改错误代码以符合您的需要
		cout << "错误: GetModuleHandle 失败" << endl;
		nRetCode = 1;
	}

	return nRetCode;
}

//Main function
void Do() {
	//Initialize COM
	CoInitialize(NULL);      
	
	//Use ATL smart pointers 
	CComPtr<ISldWorks> swApp = NULL; 
	CComPtr<IModelDoc2> swModel = NULL;
	CComPtr<IAssemblyDoc> swAssemblyDoc = NULL;
	CComPtr<IComponent2> swComponent = NULL;
	CComPtr<IFeature> mateFeature = NULL;
	CComPtr<IMate2> swMate = NULL;
	//CComPtr<IModelDocExtension> swDocExt = NULL;
	//CComPtr<IModelDoc2> tmpObj = NULL;

	try {
		//Open or attach to the currently running instance of the sldworks.exe
		//COM server on your local computer; throw an exception if
		//SolidWorks is not opened or attached to
		cout << "正在启动SolidWorks。" << endl;
		hres = swApp.CoCreateInstance(__uuidof(SldWorks), NULL, CLSCTX_LOCAL_SERVER);
		if (hres != S_OK)
			throw 0;
			
		//Open assembly
		cout << "正在打开装配体文件。" << endl;
		OpenAssembly(swApp, &swModel);

		//Resolve Assembly
		cout << "正在解析装配体文件。" << endl;
		//测试 SelectionComponent(swApp);

		GetModelAssembly(swApp);
		/*
		IComponent2* swComponent = NULL;
		//Traverse FeatureManager design tree to get specified feature
		TraverseFeatureManagerDesignTree(swModel, &swComponent);
		*/

		getchar();
	} catch (int) {
		cout << "Error starting or attaching to a SolidWorks session." << endl;
		//Release COM references
		swApp = NULL;
		swModel = NULL;
		swComponent = NULL;
		swAssemblyDoc = NULL;
		//Uninitialize COM
		CoUninitialize();
		return;
	}
}

//选择component类型的对象
void SelectionComponent(ISldWorks * m_pSldWorks)
{
	//使solidworks可见可控制
	m_pSldWorks->put_UserControl(VARIANT_TRUE);
	m_pSldWorks->put_Visible(VARIANT_TRUE);

	CComPtr<IModelDoc2>  swModel;
	m_pSldWorks->get_IActiveDoc2(&swModel);

	if(! swModel){
		return ;
	}

	CComBSTR  strModelTitle;
	long      nDocumentType;  // swDocumentTypes_e
	//获取model名和类型
	swModel->GetTitle(&strModelTitle);
	swModel->GetType(&nDocumentType);

	CComPtr<ISelectionMgr>   swSelectionManager;
	long                   lNumSelections;
	long                   nSelectionType;     // swSelectType_e 
	CComPtr<IDispatch>       swSelectedObject;
	CComPtr<IComponent2>     swComponet;

	//获取model的选择管理器，与选择数量
	swModel->get_ISelectionManager(&swSelectionManager);
	swSelectionManager->GetSelectedObjectCount2(-1, &lNumSelections);

	//从头到尾判断选择管理的类型
	for (int i = 1; i <= lNumSelections; i++) {
		swSelectionManager->GetSelectedObject6(i, -1, &swSelectedObject);
		swSelectionManager->GetSelectedObjectType3(i, -1, &nSelectionType);

		switch (nSelectionType) {
		case swSelectType_e::swSelCOMPONENTS://判断选择的是否是components类型的数据
			swSelectedObject.QueryInterface(&swComponet);
			
			CComBSTR bname;
			swComponet->get_Name(&bname);
			CString name(bname);

			cout << name << endl;
			break;

		}
	}

}

//Open assembly
void OpenAssembly(ISldWorks* swApp, IModelDoc2** swModel)
{
	CComBSTR sFileName(L"C:\\Users\\dongye\\Desktop\\装配体3.SLDASM");
	CComBSTR sDefaultConfiguration(L"Default");

	long fileerror, filewarning;

	IModelDoc2* swModelAssembly;
	//打开文件
	hres = swApp->OpenDoc6(
		sFileName, 
		swDocASSEMBLY, 
		swOpenDocOptions_Silent, 
		sDefaultConfiguration, 
		&fileerror, 
		&filewarning,
		&swModelAssembly
	);

	//Set the value of the input argument equal to address of the interface
	*swModel = swModelAssembly; 
}

void GetModelAssembly(ISldWorks* m_pSldWorks) {
	CComPtr<IConfiguration> pConfiguration = NULL;
	CComPtr<IComponent2> pRootComponent = NULL;
	CComPtr<IModelDoc2> pModelDoc = NULL;
	HRESULT hres = S_OK;
	long RecurseLevel = 0;

	hres = m_pSldWorks->get_IActiveDoc2(&pModelDoc );  
 
	// Retrieve model document pointer
	if(S_OK != hres || pModelDoc == NULL)
		return;  

	// Get the active configuration and root component
	if ((hres = pModelDoc->IGetActiveConfiguration(&pConfiguration)) == S_OK) {
		if ((hres = pConfiguration->IGetRootComponent2(&pRootComponent)) == S_OK) {
			CString MyString;
			TraverseChildren(RecurseLevel, &MyString, pRootComponent, m_pSldWorks);
			cout << MyString << endl;
		}
		//pConfiguration->Release();
	}
}

//////////////////////////////////////////////////////////////////////////
// Function: TraverseChildren
// Arguments: RecurseLevel - Level of recursion
//    MyString - Textural record of assembly
//    pComponent - Component to traverse
// Return: Number of children
// Description: Perform any operations specific to the component, then
//    if the component has children, recursively call
//    this function for each child.
//////////////////////////////////////////////////////////////////////////
int TraverseChildren(long RecurseLevel, CString* MyString, IComponent2* pComponent, ISldWorks* m_pSldWorks) {
	int   nChildren;
	int   i;
	BSTR  Name;
	HRESULT  hres = S_OK;
	IModelDoc2*  pModelDoc = NULL;

	// Retrieve the component name
	if(RecurseLevel==0) {
		// Special case of top-level components
		hres = m_pSldWorks->get_IActiveDoc2(&pModelDoc);
		pModelDoc->put_Visible(TRUE);
		if(S_OK == hres || pModelDoc != NULL)//获取文件名
			hres = pModelDoc->GetTitle(&Name);
	} else {
		// Get the component name
		hres = pComponent->get_Name2(&Name);
	}

	if(S_OK == hres && Name != NULL) { //条件成立则文件打开成功或者已获取rootComponent
		CString tempstr;
		for( i=1; i<=RecurseLevel; i++) {
			tempstr += " ";
		}

		CString Tmp(Name);
		tempstr += Tmp;
		tempstr += L"\r\n";
		*MyString = *MyString + tempstr;
	}

	RecurseLevel++;
	VARIANT componentChildren;
	HRESULT state = pComponent->GetChildren(&componentChildren);

	if(componentChildren.vt == VT_EMPTY ||  V_VT(&componentChildren) == VT_NULL ){
		return 1;
	}

	SAFEARRAY* psa = V_ARRAY(&componentChildren);
	LPDISPATCH * componentChildrenArray;
	state = SafeArrayAccessData(psa, (void **) &componentChildrenArray);
	long highIndex;
	SafeArrayGetUBound(psa,1,&highIndex);
	long childrenCount = highIndex + 1;
	for(int i = 0; i<childrenCount; i++){
		IComponent2* m_childComponent;
		componentChildrenArray[i]->QueryInterface(IID_IComponent2,(void **)&m_childComponent);
		/*componentChildrenArray[i]->AddRef();
		VARIANT_BOOL isSuppressed;
		state = m_childComponent->IsSuppressed(&isSuppressed);*/
		TraverseChildren(RecurseLevel, MyString, m_childComponent, m_pSldWorks);
	}
	state = SafeArrayUnaccessData(psa);
	state = SafeArrayDestroy(psa);
	/*hres = pComponent->IGetChildrenCount(&nChildren);
	
	// Check if this component has children
	if (S_OK == hres && nChildren > 0) {
		pChildren =  (IComponent2**) new IComponent2*[nChildren];
		hres =  pComponent->IGetChildren(pChildren);
		
		if(S_OK == hres) {
			for (i=0; i<nChildren; i++){
				
				TraverseChildren(RecurseLevel, MyString, *pChildren + i * sizeof(IComponent2*), m_pSldWorks);
				pChildren[i]->Release();
			}
		}

		if (*pChildren != NULL)
		delete []pChildren;
	}
	*/
	RecurseLevel--;
	return childrenCount;
}

// Traverse FeatureManager design tree to get the
// specified feature in FeatureManager design tree
void TraverseFeatureManagerDesignTree(IModelDoc2* swModel, IComponent2** swComponent) {
	//Use ATL smart pointers
	CComPtr<IFeature> swFeature;
	CComPtr<ISelectionMgr> swSelMgr;
	CComBSTR sGetFeatureName(L"");
	CComBSTR sFeatureName(L"knee-1");

	bool bFoundComponents = false;
	hres = swModel->IFirstFeature(&swFeature);
	 
	// If the name of the feature is "bracket-1"
	// then select the feature
	do {
		hres = swFeature->get_Name(&sGetFeatureName);
		if (sGetFeatureName == sFeatureName) {
			hres = swFeature->Select2(true, 1, &retVal);
			hres = swModel->get_ISelectionManager(&swSelMgr);
			struct IDispatch *pComponentDisp;
			hres = swSelMgr->GetSelectedObject6(1, -1, &pComponentDisp);
			IComponent2* swSelectedComponent;
			hres = pComponentDisp->QueryInterface(
				__uuidof(IComponent2), 
				reinterpret_cast<void**>(&swSelectedComponent)
			);
			
			pComponentDisp->Release();

			//Set the value of the input argument equal to address of the interface
			*swComponent = swSelectedComponent; 
			bFoundComponents = true;
		} else {
			//Get next feature
			CComPtr<IFeature> swFeatureNext;
			hres = swFeature->IGetNextFeature(&swFeatureNext);
			swFeature.Release();
			swFeature = swFeatureNext;
		}
	} while (!bFoundComponents);
}

/*
void SuppressSelectedComponent(IComponent2* swComponent, ISldWorks* swApp)
//Suppress selected component if it is resolved
{
CComBSTR messageSuppressed (L"Component is already suppressed.");

 

long lComponentSuppressState;

long lSuppressMessageResult;

long lSuppressError;

 

hres = swComponent->GetSuppression(&lComponentSuppressState);

if (lComponentSuppressState == swComponentSuppressed)

hres = swApp->SendMsgToUser2(messageSuppressed, swMbInformation, swMbOk, &lSuppressMessageResult);

else

hres = swComponent->SetSuppression2(swComponentSuppressed, &lSuppressError);

}

 

void ResolveSelectedComponent(IComponent2* swComponent, ISldWorks* swApp)

//Resolve selected component if it is suppressed

{

CComBSTR messageResolved (L"Component is already resolved.");

 

long lComponentResolveState;

long lResolveMessageResult;

long lResolveError;

 

hres = swComponent->GetSuppression(&lComponentResolveState);

if (lComponentResolveState == swComponentFullyResolved)

hres = swApp->SendMsgToUser2(messageResolved, swMbInformation, swMbOk, &lResolveMessageResult);

else

hres = swComponent->SetSuppression2(swComponentFullyResolved, &lResolveError);

}

 

void ExplodeAssembly(IModelDoc2* swModel, IAssemblyDoc** swAssemblyDoc)

//Explode assembly

{

CComPtr<IModelView> swExplodeModelView;

 

double dZoomFactorOut = 0.3;

 

IAssemblyDoc* swThisAssemblyDoc;

hres = swModel->get_IActiveView(&swExplodeModelView);

hres = swExplodeModelView->ZoomByFactor(dZoomFactorOut);

hres = swModel->QueryInterface(__uuidof(IAssemblyDoc), reinterpret_cast<void**>(&swThisAssemblyDoc));

hres = swThisAssemblyDoc->AutoExplode(&retVal);

*swAssemblyDoc = swThisAssemblyDoc;

}

 

void CollapseAssembly(IModelDoc2* swModel, IAssemblyDoc* swAssemblyDoc)

//Collapse assembly

{

hres = swAssemblyDoc->AutoExplode(&retVal);

hres = swAssemblyDoc->ViewCollapseAssembly();

hres = swModel->ViewZoomtofit2();

}

 

void CreateDrawingOfAssembly(ISldWorks* swApp, IModelDoc2* swModel)

//Create a drawing of the assembly

{

CComPtr<IModelDoc2> swNewModel;

CComPtr<IModelDocExtension> swModelDocExt;

CComPtr<IDrawingDoc> swDrawingDoc;

 

CComBSTR sDrawingDocTemplate (L"c:\\Program Files\\SolidWorks\\data\\templates\\Drawing.drwdot");

CComBSTR sActiveAssembly (L"c:\\test\\universaljoint\\ujoint.sldasm");

CComBSTR sDrawingDocName (L"ujoint - Sheet1");

 

double dWidth = 0.2794;

double dHeight = 0.4318;

long lPaperSize = 2;

long lWindowStyle = 2;

long lErrorActivatingDoc;

hres = swApp->INewDocument2(sDrawingDocTemplate, lPaperSize, dWidth, dHeight, &swNewModel);

swDrawingDoc = swNewModel;

hres = swApp->ArrangeWindows(lWindowStyle);

hres = swModel->Release();

hres = swApp->IActivateDoc3(sActiveAssembly, false, &lErrorActivatingDoc, &swModel);

hres = swModel->get_Extension(&swModelDocExt);

hres = swModelDocExt->SelectByID2(sActiveAssembly, L"COMPONENT", 0.0, 0.0, 0.0, VARIANT_FALSE, 0, NULL, swSelectOptionDefault, &retVal);

swNewModel.Release();

hres = swApp->IActivateDoc3(sDrawingDocName, false, &lErrorActivatingDoc, &swNewModel);

hres = swDrawingDoc->Create3rdAngleViews(sActiveAssembly, &retVal);

}

void CloseDocuments(ISldWorks* swApp)

//Close assembly and drawing documents

{

swApp->CloseAllDocuments(true, &retVal);

}
*/