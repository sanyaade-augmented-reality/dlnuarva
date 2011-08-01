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

using namespace std;

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

//Open assembly
void OpenAssembly(ISldWorks* swApp, IModelDoc2** swModel)
{
	CComBSTR sFileName(L"D:\\MyWorks\\Virtual Assembly\\SolidWorks Study\\mill.SLDASM");
	CComBSTR sDefaultConfiguration(L"Default");

	long fileerror, filewarning;

	IModelDoc2* swModelAssembly;
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
		if ((hres = pConfiguration->GetRootComponent3(TRUE, &pRootComponent)) == S_OK) {
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
	IComponent2** pChildren;
	int   nChildren;
	int   i;
	BSTR  Name;
	HRESULT  hres = S_OK;
	IModelDoc2*  pModelDoc = NULL;

	// Retrieve the component name
	if(RecurseLevel==0) {
		// Special case of top-level components
		hres = m_pSldWorks->get_IActiveDoc2(&pModelDoc);
		if(S_OK == hres || pModelDoc != NULL)
			hres = pModelDoc->GetTitle(&Name);
	} else {
		// Get the component name
		hres = pComponent->get_Name2(&Name);
	}

	if(S_OK == hres && Name != NULL) {
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
	hres = pComponent->IGetChildrenCount(&nChildren);

	// Check if this component has children
	if (S_OK == hres && nChildren > 0) {
		pChildren =  (IComponent2**)new IComponent2*[nChildren];
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

	RecurseLevel--;
	return nChildren;
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