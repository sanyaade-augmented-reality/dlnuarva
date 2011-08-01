// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装类

#import "D:\\PROGRA~1\\SOLIDW~1\\SOLIDW~1\\sldworks.tlb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "D:\\PROGRA~1\\SOLIDW~1\\SOLIDW~1\\swconst.tlb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
// CSldWorks 包装类

class CSldWorks : public COleDispatchDriver
{
public:
	CSldWorks(){} // 调用 COleDispatchDriver 默认构造函数
	CSldWorks(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CSldWorks(const CSldWorks& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// ISldWorks 方法
public:
	LPDISPATCH get_ActiveDoc()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_IActiveDoc()
	{
		LPDISPATCH result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH OpenDoc(LPCTSTR Name, long Type)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Name, Type);
		return result;
	}
	LPDISPATCH IOpenDoc(LPCTSTR Name, long Type)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Name, Type);
		return result;
	}
	LPDISPATCH ActivateDoc(LPCTSTR Name)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Name);
		return result;
	}
	LPDISPATCH IActivateDoc(LPCTSTR Name)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Name);
		return result;
	}
	void SendMsgToUser(LPCTSTR Message)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Message);
	}
	LPDISPATCH Frame()
	{
		LPDISPATCH result;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH IFrameObject()
	{
		LPDISPATCH result;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void ExitApp()
	{
		InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void CloseDoc(LPCTSTR Name)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Name);
	}
	LPDISPATCH NewPart()
	{
		LPDISPATCH result;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH INewPart()
	{
		LPDISPATCH result;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH NewAssembly()
	{
		LPDISPATCH result;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH INewAssembly()
	{
		LPDISPATCH result;
		InvokeHelper(0x15, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH NewDrawing(long TemplateToUse)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, TemplateToUse);
		return result;
	}
	LPDISPATCH INewDrawing(long TemplateToUse)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x16, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, TemplateToUse);
		return result;
	}
	long DateCode()
	{
		long result;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	CString RevisionNumber()
	{
		CString result;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	BOOL LoadFile(LPCTSTR FileName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, FileName);
		return result;
	}
	BOOL AddFileOpenItem(LPCTSTR CallbackFcnAndModule, LPCTSTR Description)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, CallbackFcnAndModule, Description);
		return result;
	}
	BOOL AddFileSaveAsItem(LPCTSTR CallbackFcnAndModule, LPCTSTR Description, long Type)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_I4 ;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, CallbackFcnAndModule, Description, Type);
		return result;
	}
	void PreSelectDwgTemplateSize(long TemplateToUse, LPCTSTR TemplateName)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_EMPTY, NULL, parms, TemplateToUse, TemplateName);
	}
	void DocumentVisible(BOOL Visible, long Type)
	{
		static BYTE parms[] = VTS_BOOL VTS_I4 ;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Visible, Type);
	}
	LPDISPATCH DefineAttribute(LPCTSTR Name)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x19, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Name);
		return result;
	}
	LPDISPATCH IDefineAttribute(LPCTSTR Name)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x1a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Name);
		return result;
	}
	BOOL get_Visible()
	{
		BOOL result;
		InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Visible(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x1b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_UserControl()
	{
		BOOL result;
		InvokeHelper(0x1c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_UserControl(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x1c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void DisplayStatusBar(BOOL OnOff)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x1d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, OnOff);
	}
	void CreateNewWindow()
	{
		InvokeHelper(0x1e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void ArrangeIcons()
	{
		InvokeHelper(0x1f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void ArrangeWindows(long Style)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x20, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Style);
	}
	void QuitDoc(LPCTSTR Name)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x21, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Name);
	}
	LPDISPATCH GetModeler()
	{
		LPDISPATCH result;
		InvokeHelper(0x22, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH IGetModeler()
	{
		LPDISPATCH result;
		InvokeHelper(0x23, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH GetEnvironment()
	{
		LPDISPATCH result;
		InvokeHelper(0x24, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH IGetEnvironment()
	{
		LPDISPATCH result;
		InvokeHelper(0x25, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH NewDrawing2(long TemplateToUse, LPCTSTR TemplateName, long PaperSize, double Width, double Height)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_R8 VTS_R8 ;
		InvokeHelper(0x26, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, TemplateToUse, TemplateName, PaperSize, Width, Height);
		return result;
	}
	LPDISPATCH INewDrawing2(long TemplateToUse, LPCTSTR TemplateName, long PaperSize, double Width, double Height)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_R8 VTS_R8 ;
		InvokeHelper(0x27, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, TemplateToUse, TemplateName, PaperSize, Width, Height);
		return result;
	}
	BOOL SetOptions(LPCTSTR Message)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x28, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Message);
		return result;
	}
	BOOL PreviewDoc(long * HWnd, LPCTSTR FullName)
	{
		BOOL result;
		static BYTE parms[] = VTS_PI4 VTS_BSTR ;
		InvokeHelper(0x29, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, HWnd, FullName);
		return result;
	}
	CString GetSearchFolders(long FolderType)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x2a, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, FolderType);
		return result;
	}
	BOOL SetSearchFolders(long FolderType, LPCTSTR Folders)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x2b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, FolderType, Folders);
		return result;
	}
	BOOL GetUserPreferenceToggle(long UserPreferenceToggle)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x2c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, UserPreferenceToggle);
		return result;
	}
	void SetUserPreferenceToggle(long UserPreferenceValue, BOOL OnFlag)
	{
		static BYTE parms[] = VTS_I4 VTS_BOOL ;
		InvokeHelper(0x2d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, UserPreferenceValue, OnFlag);
	}
	double GetUserPreferenceDoubleValue(long UserPreferenceValue)
	{
		double result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x2e, DISPATCH_METHOD, VT_R8, (void*)&result, parms, UserPreferenceValue);
		return result;
	}
	BOOL SetUserPreferenceDoubleValue(long UserPreferenceValue, double Value)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_R8 ;
		InvokeHelper(0x2f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, UserPreferenceValue, Value);
		return result;
	}
	CString get_ActivePrinter()
	{
		CString result;
		InvokeHelper(0x30, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_ActivePrinter(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x30, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL LoadFile2(LPCTSTR FileName, LPCTSTR ArgString)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x31, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, FileName, ArgString);
		return result;
	}
	long GetUserPreferenceIntegerValue(long UserPreferenceValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x32, DISPATCH_METHOD, VT_I4, (void*)&result, parms, UserPreferenceValue);
		return result;
	}
	BOOL SetUserPreferenceIntegerValue(long UserPreferenceValue, long Value)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x33, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, UserPreferenceValue, Value);
		return result;
	}
	BOOL RemoveMenuPopupItem(long DocType, long SelectType, LPCTSTR Item, LPCTSTR CallbackFcnAndModule, LPCTSTR CustomNames, long Unused)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 ;
		InvokeHelper(0x34, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, DocType, SelectType, Item, CallbackFcnAndModule, CustomNames, Unused);
		return result;
	}
	BOOL RemoveMenu(long DocType, LPCTSTR MenuItemString, LPCTSTR CallbackFcnAndModule)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x35, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, DocType, MenuItemString, CallbackFcnAndModule);
		return result;
	}
	BOOL RemoveFileOpenItem(LPCTSTR CallbackFcnAndModule, LPCTSTR Description)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x36, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, CallbackFcnAndModule, Description);
		return result;
	}
	BOOL RemoveFileSaveAsItem(LPCTSTR CallbackFcnAndModule, LPCTSTR Description, long Type)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_I4 ;
		InvokeHelper(0x37, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, CallbackFcnAndModule, Description, Type);
		return result;
	}
	BOOL ReplaceReferencedDocument(LPCTSTR ReferencingDocument, LPCTSTR ReferencedDocument, LPCTSTR NewReference)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x38, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ReferencingDocument, ReferencedDocument, NewReference);
		return result;
	}
	long AddMenuItem(long DocType, LPCTSTR Menu, long Postion, LPCTSTR CallbackModuleAndFcn)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_BSTR ;
		InvokeHelper(0x39, DISPATCH_METHOD, VT_I4, (void*)&result, parms, DocType, Menu, Postion, CallbackModuleAndFcn);
		return result;
	}
	long AddMenuPopupItem(long DocType, long SelType, LPCTSTR Item, LPCTSTR CallbackFcnAndModule, LPCTSTR CustomNames)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x3a, DISPATCH_METHOD, VT_I4, (void*)&result, parms, DocType, SelType, Item, CallbackFcnAndModule, CustomNames);
		return result;
	}
	BOOL RemoveUserMenu(long DocType, long MenuIdIn, LPCTSTR ModuleName)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR ;
		InvokeHelper(0x3b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, DocType, MenuIdIn, ModuleName);
		return result;
	}
	long AddToolbar(LPCTSTR ModuleName, LPCTSTR Title, long SmallBitmapHandle, long LargeBitmapHandle)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 ;
		InvokeHelper(0x3c, DISPATCH_METHOD, VT_I4, (void*)&result, parms, ModuleName, Title, SmallBitmapHandle, LargeBitmapHandle);
		return result;
	}
	BOOL AddToolbarCommand(LPCTSTR ModuleName, long ToolbarId, long ToolbarIndex, LPCTSTR CommandString)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 VTS_BSTR ;
		InvokeHelper(0x3d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ModuleName, ToolbarId, ToolbarIndex, CommandString);
		return result;
	}
	BOOL ShowToolbar(LPCTSTR ModuleName, long ToolbarId)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x3e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ModuleName, ToolbarId);
		return result;
	}
	BOOL HideToolbar(LPCTSTR ModuleName, long ToolbarId)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x3f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ModuleName, ToolbarId);
		return result;
	}
	BOOL RemoveToolbar(LPCTSTR Module, long ToolbarId)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x40, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Module, ToolbarId);
		return result;
	}
	BOOL GetToolbarState(LPCTSTR Module, long ToolbarId, long ToolbarState)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 ;
		InvokeHelper(0x41, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Module, ToolbarId, ToolbarState);
		return result;
	}
	CString GetUserPreferenceStringListValue(long UserPreference)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x42, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, UserPreference);
		return result;
	}
	void SetUserPreferenceStringListValue(long UserPreference, LPCTSTR Value)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x43, DISPATCH_METHOD, VT_EMPTY, NULL, parms, UserPreference, Value);
	}
	BOOL EnableStereoDisplay(BOOL BEnable)
	{
		BOOL result;
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x44, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, BEnable);
		return result;
	}
	BOOL IEnableStereoDisplay(BOOL BEnable)
	{
		BOOL result;
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x45, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, BEnable);
		return result;
	}
	VARIANT GetDocumentDependencies(LPCTSTR Document, long Traverseflag, long Searchflag)
	{
		VARIANT result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 ;
		InvokeHelper(0x46, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, Document, Traverseflag, Searchflag);
		return result;
	}
	CString IGetDocumentDependencies(LPCTSTR Document, long Traverseflag, long Searchflag)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 ;
		InvokeHelper(0x47, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, Document, Traverseflag, Searchflag);
		return result;
	}
	long GetDocumentDependenciesCount(LPCTSTR Document, long Traverseflag, long Searchflag)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 ;
		InvokeHelper(0x48, DISPATCH_METHOD, VT_I4, (void*)&result, parms, Document, Traverseflag, Searchflag);
		return result;
	}
	LPDISPATCH OpenDocSilent(LPCTSTR FileName, long Type, long * Errors)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0x49, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, FileName, Type, Errors);
		return result;
	}
	LPDISPATCH IOpenDocSilent(LPCTSTR FileName, long Type, long * Errors)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0x4a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, FileName, Type, Errors);
		return result;
	}
	long CallBack(LPCTSTR CallBackFunc, long DefaultRetVal, LPCTSTR CallBackArgs)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_BSTR ;
		InvokeHelper(0x4b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, CallBackFunc, DefaultRetVal, CallBackArgs);
		return result;
	}
	long SendMsgToUser2(LPCTSTR Message, long Icon, long Buttons)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 ;
		InvokeHelper(0x4c, DISPATCH_METHOD, VT_I4, (void*)&result, parms, Message, Icon, Buttons);
		return result;
	}
	LPUNKNOWN EnumDocuments()
	{
		LPUNKNOWN result;
		InvokeHelper(0x4d, DISPATCH_METHOD, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	long LoadAddIn(LPCTSTR FileName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x4e, DISPATCH_METHOD, VT_I4, (void*)&result, parms, FileName);
		return result;
	}
	long UnloadAddIn(LPCTSTR FileName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x4f, DISPATCH_METHOD, VT_I4, (void*)&result, parms, FileName);
		return result;
	}
	BOOL RecordLine(LPCTSTR Text)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x50, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Text);
		return result;
	}
	VARIANT VersionHistory(LPCTSTR FileName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x51, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, FileName);
		return result;
	}
	CString IVersionHistory(LPCTSTR FileName)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x52, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, FileName);
		return result;
	}
	long IGetVersionHistoryCount(LPCTSTR FileName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x53, DISPATCH_METHOD, VT_I4, (void*)&result, parms, FileName);
		return result;
	}
	BOOL AllowFailedFeatureCreation(BOOL YesNo)
	{
		BOOL result;
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x54, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, YesNo);
		return result;
	}
	LPDISPATCH GetFirstDocument()
	{
		LPDISPATCH result;
		InvokeHelper(0x55, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString GetCurrentWorkingDirectory()
	{
		CString result;
		InvokeHelper(0x56, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	BOOL SetCurrentWorkingDirectory(LPCTSTR CurrentWorkingDirectory)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x57, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, CurrentWorkingDirectory);
		return result;
	}
	CString GetDataFolder(BOOL BShowErrorMsg)
	{
		CString result;
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x58, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, BShowErrorMsg);
		return result;
	}
	BOOL GetSelectionFilter(long SelType)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x59, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, SelType);
		return result;
	}
	void SetSelectionFilter(long SelType, BOOL State)
	{
		static BYTE parms[] = VTS_I4 VTS_BOOL ;
		InvokeHelper(0x5a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, SelType, State);
	}
	LPDISPATCH ActivateDoc2(LPCTSTR Name, BOOL Silent, long * Errors)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_BOOL VTS_PI4 ;
		InvokeHelper(0x5b, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Name, Silent, Errors);
		return result;
	}
	LPDISPATCH IActivateDoc2(LPCTSTR Name, BOOL Silent, long * Errors)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_BOOL VTS_PI4 ;
		InvokeHelper(0x5c, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Name, Silent, Errors);
		return result;
	}
	BOOL GetMouseDragMode(long Command)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x5d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Command);
		return result;
	}
	CString GetCurrentLanguage()
	{
		CString result;
		InvokeHelper(0x5e, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH IGetFirstDocument()
	{
		LPDISPATCH result;
		InvokeHelper(0x5f, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	BOOL SanityCheck(long SwItemToCheck, long * P1, long * P2)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x60, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, SwItemToCheck, P1, P2);
		return result;
	}
	long AddMenu(long DocType, LPCTSTR Menu, long Position)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 ;
		InvokeHelper(0x61, DISPATCH_METHOD, VT_I4, (void*)&result, parms, DocType, Menu, Position);
		return result;
	}
	long CheckpointConvertedDocument(LPCTSTR DocName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x62, DISPATCH_METHOD, VT_I4, (void*)&result, parms, DocName);
		return result;
	}
	LPDISPATCH OpenDoc2(LPCTSTR FileName, long Type, BOOL ReadOnly, BOOL ViewOnly, BOOL Silent, long * Errors)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_BOOL VTS_BOOL VTS_BOOL VTS_PI4 ;
		InvokeHelper(0x63, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, FileName, Type, ReadOnly, ViewOnly, Silent, Errors);
		return result;
	}
	LPDISPATCH IOpenDoc2(LPCTSTR FileName, long Type, BOOL ReadOnly, BOOL ViewOnly, BOOL Silent, long * Errors)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_BOOL VTS_BOOL VTS_BOOL VTS_PI4 ;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, FileName, Type, ReadOnly, ViewOnly, Silent, Errors);
		return result;
	}
	VARIANT GetMassProperties(LPCTSTR FilePathName, LPCTSTR ConfigurationName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, FilePathName, ConfigurationName);
		return result;
	}
	BOOL IGetMassProperties(LPCTSTR FilePathName, LPCTSTR ConfigurationName, double * MPropsData)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_PR8 ;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, FilePathName, ConfigurationName, MPropsData);
		return result;
	}
	CString GetLocalizedMenuName(long MenuId)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x67, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, MenuId);
		return result;
	}
	VARIANT GetDocumentDependencies2(LPCTSTR Document, BOOL Traverseflag, BOOL Searchflag, BOOL AddReadOnlyInfo)
	{
		VARIANT result;
		static BYTE parms[] = VTS_BSTR VTS_BOOL VTS_BOOL VTS_BOOL ;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, Document, Traverseflag, Searchflag, AddReadOnlyInfo);
		return result;
	}
	CString IGetDocumentDependencies2(LPCTSTR Document, BOOL Traverseflag, BOOL Searchflag, BOOL AddReadOnlyInfo)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BOOL VTS_BOOL VTS_BOOL ;
		InvokeHelper(0x69, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, Document, Traverseflag, Searchflag, AddReadOnlyInfo);
		return result;
	}
	long IGetDocumentDependenciesCount2(LPCTSTR Document, BOOL Traverseflag, BOOL Searchflag, BOOL AddReadOnlyInfo)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BOOL VTS_BOOL VTS_BOOL ;
		InvokeHelper(0x6a, DISPATCH_METHOD, VT_I4, (void*)&result, parms, Document, Traverseflag, Searchflag, AddReadOnlyInfo);
		return result;
	}
	VARIANT GetSelectionFilters()
	{
		VARIANT result;
		InvokeHelper(0x6b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void SetSelectionFilters(VARIANT& SelType, BOOL State)
	{
		static BYTE parms[] = VTS_VARIANT VTS_BOOL ;
		InvokeHelper(0x6c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &SelType, State);
	}
	BOOL GetApplySelectionFilter()
	{
		BOOL result;
		InvokeHelper(0x6d, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void SetApplySelectionFilter(BOOL State)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x6e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, State);
	}
	LPDISPATCH NewDocument(LPCTSTR TemplateName, long PaperSize, double Width, double Height)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_R8 VTS_R8 ;
		InvokeHelper(0x6f, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, TemplateName, PaperSize, Width, Height);
		return result;
	}
	LPDISPATCH INewDocument(LPCTSTR TemplateName, long PaperSize, double Width, double Height)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_R8 VTS_R8 ;
		InvokeHelper(0x70, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, TemplateName, PaperSize, Width, Height);
		return result;
	}
	CString GetDocumentTemplate(long Mode, LPCTSTR TemplateName, long PaperSize, double Width, double Height)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_R8 VTS_R8 ;
		InvokeHelper(0x71, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, Mode, TemplateName, PaperSize, Width, Height);
		return result;
	}
	long IGetSelectionFiltersCount()
	{
		long result;
		InvokeHelper(0x72, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long IGetSelectionFilters()
	{
		long result;
		InvokeHelper(0x73, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	void ISetSelectionFilters(long Count, long * SelType, BOOL State)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_BOOL ;
		InvokeHelper(0x74, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Count, SelType, State);
	}
	CString GetCurrSolidWorksRegSubKey()
	{
		CString result;
		InvokeHelper(0x75, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void SolidWorksExplorer()
	{
		InvokeHelper(0x76, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	CString GetUserPreferenceStringValue(long UserPreference)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x77, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, UserPreference);
		return result;
	}
	BOOL SetUserPreferenceStringValue(long UserPreference, LPCTSTR Value)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x78, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, UserPreference, Value);
		return result;
	}
	CString GetCurrentMacroPathName()
	{
		CString result;
		InvokeHelper(0x79, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH GetOpenDocumentByName(LPCTSTR DocumentName)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x7a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, DocumentName);
		return result;
	}
	LPDISPATCH IGetOpenDocumentByName(LPCTSTR DocumentName)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x7b, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, DocumentName);
		return result;
	}
	void GetCurrentKernelVersions(BSTR * Version1, BSTR * Version2, BSTR * Version3)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0x7c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Version1, Version2, Version3);
	}
	CString CreatePrunedModelArchive(LPCTSTR PathName, LPCTSTR ZipPathName)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x7d, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, PathName, ZipPathName);
		return result;
	}
	LPDISPATCH OpenDoc3(LPCTSTR FileName, long Type, BOOL ReadOnly, BOOL ViewOnly, BOOL RapidDraft, BOOL Silent, long * Errors)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_BOOL VTS_BOOL VTS_BOOL VTS_BOOL VTS_PI4 ;
		InvokeHelper(0x7e, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, FileName, Type, ReadOnly, ViewOnly, RapidDraft, Silent, Errors);
		return result;
	}
	LPDISPATCH IOpenDoc3(LPCTSTR FileName, long Type, BOOL ReadOnly, BOOL ViewOnly, BOOL RapidDraft, BOOL Silent, long * Errors)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_BOOL VTS_BOOL VTS_BOOL VTS_BOOL VTS_PI4 ;
		InvokeHelper(0x7f, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, FileName, Type, ReadOnly, ViewOnly, RapidDraft, Silent, Errors);
		return result;
	}
	long AddToolbar2(LPCTSTR ModuleNameIn, LPCTSTR TitleIn, long SmallBitmapHandleIn, long LargeBitmapHandleIn, long MenuPosIn, long DecTemplateTypeIn)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x80, DISPATCH_METHOD, VT_I4, (void*)&result, parms, ModuleNameIn, TitleIn, SmallBitmapHandleIn, LargeBitmapHandleIn, MenuPosIn, DecTemplateTypeIn);
		return result;
	}
	LPDISPATCH OpenModelConfiguration(LPCTSTR PathName, LPCTSTR ConfigName)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x81, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, PathName, ConfigName);
		return result;
	}
	long GetToolbarDock(LPCTSTR ModuleIn, long ToolbarIDIn)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x82, DISPATCH_METHOD, VT_I4, (void*)&result, parms, ModuleIn, ToolbarIDIn);
		return result;
	}
	void SetToolbarDock(LPCTSTR ModuleIn, long ToolbarIDIn, long DocStatePosIn)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 ;
		InvokeHelper(0x83, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ModuleIn, ToolbarIDIn, DocStatePosIn);
	}
	LPDISPATCH GetMathUtility()
	{
		LPDISPATCH result;
		InvokeHelper(0x84, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH IGetMathUtility()
	{
		LPDISPATCH result;
		InvokeHelper(0x85, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH OpenDoc4(LPCTSTR FileName, long Type, long Options, LPCTSTR Configuration, long * Errors)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x86, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, FileName, Type, Options, Configuration, Errors);
		return result;
	}
	LPDISPATCH IOpenDoc4(LPCTSTR FileName, long Type, long Options, LPCTSTR Configuration, long * Errors)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x87, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, FileName, Type, Options, Configuration, Errors);
		return result;
	}
	BOOL IsRapidDraft(LPCTSTR FileName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x88, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, FileName);
		return result;
	}
	VARIANT GetTemplateSizes(LPCTSTR FileName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x89, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, FileName);
		return result;
	}
	BOOL IGetTemplateSizes(LPCTSTR FileName, long * PaperSize, double * Width, double * Height)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PI4 VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x8a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, FileName, PaperSize, Width, Height);
		return result;
	}
	LPDISPATCH GetColorTable()
	{
		LPDISPATCH result;
		InvokeHelper(0x8b, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH IGetColorTable()
	{
		LPDISPATCH result;
		InvokeHelper(0x8c, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void SetMissingReferencePathName(LPCTSTR FileName)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x8d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName);
	}
	LPDISPATCH GetUserUnit(long UnitType)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x8e, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, UnitType);
		return result;
	}
	LPDISPATCH IGetUserUnit(long UnitType)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x8f, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, UnitType);
		return result;
	}
	BOOL SetMouseDragMode(long Command)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x90, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Command);
		return result;
	}
	void SetPromptFilename(LPCTSTR FileName)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x91, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName);
	}
	BOOL SetAddinCallbackInfo(long ModuleHandle, LPDISPATCH AddinCallbacks, long Cookie)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_DISPATCH VTS_I4 ;
		InvokeHelper(0x92, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ModuleHandle, AddinCallbacks, Cookie);
		return result;
	}
	BOOL AddMenuItem2(long DocumentType, long Cookie, LPCTSTR MenuItem, long Position, LPCTSTR MenuCallback, LPCTSTR MenuEnableMethod, LPCTSTR HintString)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x93, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, DocumentType, Cookie, MenuItem, Position, MenuCallback, MenuEnableMethod, HintString);
		return result;
	}
	long AddToolbar3(long Cookie, LPCTSTR Title, long SmallBitmapResourceID, long LargeBitmapResourceID, long MenuPositionForToolbar, long DocumentType)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x94, DISPATCH_METHOD, VT_I4, (void*)&result, parms, Cookie, Title, SmallBitmapResourceID, LargeBitmapResourceID, MenuPositionForToolbar, DocumentType);
		return result;
	}
	BOOL RemoveToolbar2(long Cookie, long ToolbarId)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x95, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Cookie, ToolbarId);
		return result;
	}
	BOOL AddToolbarCommand2(long Cookie, long ToolbarId, long ToolbarIndex, LPCTSTR ButtonCallback, LPCTSTR ButtonEnableMethod, LPCTSTR ToolTip, LPCTSTR HintString)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x96, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Cookie, ToolbarId, ToolbarIndex, ButtonCallback, ButtonEnableMethod, ToolTip, HintString);
		return result;
	}
	BOOL ShowToolbar2(long Cookie, long ToolbarId)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x97, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Cookie, ToolbarId);
		return result;
	}
	BOOL HideToolbar2(long Cookie, long ToolbarId)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x98, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Cookie, ToolbarId);
		return result;
	}
	BOOL GetToolbarState2(long Cookie, long ToolbarId, long ToolbarState)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x99, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Cookie, ToolbarId, ToolbarState);
		return result;
	}
	long GetToolbarDock2(long Cookie, long ToolbarId)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x9a, DISPATCH_METHOD, VT_I4, (void*)&result, parms, Cookie, ToolbarId);
		return result;
	}
	BOOL SetToolbarDock2(long Cookie, long ToolbarId, long DockingState)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x9b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Cookie, ToolbarId, DockingState);
		return result;
	}
	LPDISPATCH get_IActiveDoc2()
	{
		LPDISPATCH result;
		InvokeHelper(0x9c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH IActivateDoc3(LPCTSTR Name, BOOL Silent, long * Errors)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_BOOL VTS_PI4 ;
		InvokeHelper(0x9d, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Name, Silent, Errors);
		return result;
	}
	LPDISPATCH IGetFirstDocument2()
	{
		LPDISPATCH result;
		InvokeHelper(0x9e, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH INewDocument2(LPCTSTR TemplateName, long PaperSize, double Width, double Height)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_R8 VTS_R8 ;
		InvokeHelper(0x9f, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, TemplateName, PaperSize, Width, Height);
		return result;
	}
	LPDISPATCH IGetOpenDocumentByName2(LPCTSTR DocumentName)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xa0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, DocumentName);
		return result;
	}
	LPDISPATCH IOpenDoc5(LPCTSTR FileName, long Type, long Options, LPCTSTR Configuration, long * Errors)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xa1, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, FileName, Type, Options, Configuration, Errors);
		return result;
	}
	LPUNKNOWN EnumDocuments2()
	{
		LPUNKNOWN result;
		InvokeHelper(0xa2, DISPATCH_METHOD, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH CreatePropertyManagerPage(LPCTSTR Title, long Options, LPDISPATCH Handler, long * Errors)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_DISPATCH VTS_PI4 ;
		InvokeHelper(0xa3, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Title, Options, Handler, Errors);
		return result;
	}
	LPDISPATCH ICreatePropertyManagerPage(LPCTSTR Title, long Options, LPDISPATCH Handler, long * Errors)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_DISPATCH VTS_PI4 ;
		InvokeHelper(0xa4, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Title, Options, Handler, Errors);
		return result;
	}
	LPDISPATCH GetAddInObject(LPCTSTR Clsid)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xa5, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Clsid);
		return result;
	}
	long GetProcessID()
	{
		long result;
		InvokeHelper(0xa6, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH OpenDoc6(LPCTSTR FileName, long Type, long Options, LPCTSTR Configuration, long * Errors, long * Warnings)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 VTS_BSTR VTS_PI4 VTS_PI4 ;
		InvokeHelper(0xa7, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, FileName, Type, Options, Configuration, Errors, Warnings);
		return result;
	}
	BOOL AddFileOpenItem2(long Cookie, LPCTSTR MethodName, LPCTSTR Description, LPCTSTR Extension)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xa8, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Cookie, MethodName, Description, Extension);
		return result;
	}
	BOOL RemoveFileOpenItem2(long Cookie, LPCTSTR MethodName, LPCTSTR Description, LPCTSTR Extension)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xa9, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Cookie, MethodName, Description, Extension);
		return result;
	}
	BOOL AddFileSaveAsItem2(long Cookie, LPCTSTR MethodName, LPCTSTR Description, LPCTSTR Extension, long DocumentType)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 ;
		InvokeHelper(0xaa, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Cookie, MethodName, Description, Extension, DocumentType);
		return result;
	}
	BOOL RemoveFileSaveAsItem2(long Cookie, LPCTSTR MethodName, LPCTSTR Description, LPCTSTR Extension, long DocumentType)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 ;
		InvokeHelper(0xab, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Cookie, MethodName, Description, Extension, DocumentType);
		return result;
	}
	BOOL AddMenuPopupItem2(long DocumentType, long Cookie, long SelectType, LPCTSTR PopupItemName, LPCTSTR MenuCallback, LPCTSTR MenuEnableMethod, LPCTSTR HintString, LPCTSTR CustomNames)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xac, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, DocumentType, Cookie, SelectType, PopupItemName, MenuCallback, MenuEnableMethod, HintString, CustomNames);
		return result;
	}
	BOOL RemoveMenuPopupItem2(long DocumentType, long Cookie, long SelectType, LPCTSTR PopupItemName, LPCTSTR MenuCallback, LPCTSTR MenuEnableMethod, LPCTSTR HintString, LPCTSTR CustomNames)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xad, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, DocumentType, Cookie, SelectType, PopupItemName, MenuCallback, MenuEnableMethod, HintString, CustomNames);
		return result;
	}
	VARIANT GetMassProperties2(LPCTSTR FilePathName, LPCTSTR ConfigurationName, long Accuracy)
	{
		VARIANT result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_I4 ;
		InvokeHelper(0xae, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, FilePathName, ConfigurationName, Accuracy);
		return result;
	}
	BOOL IGetMassProperties2(LPCTSTR FilePathName, LPCTSTR ConfigurationName, double * MPropsData, long Accuracy)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_PR8 VTS_I4 ;
		InvokeHelper(0xaf, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, FilePathName, ConfigurationName, MPropsData, Accuracy);
		return result;
	}
	void HighlightTBButton(long CmdID)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xb0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, CmdID);
	}
	BOOL RunMacro(LPCTSTR FilePathName, LPCTSTR ModuleName, LPCTSTR ProcedureName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xb1, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, FilePathName, ModuleName, ProcedureName);
		return result;
	}
	long GetConfigurationCount(LPCTSTR FilePathName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xb2, DISPATCH_METHOD, VT_I4, (void*)&result, parms, FilePathName);
		return result;
	}
	VARIANT GetConfigurationNames(LPCTSTR FilePathName)
	{
		VARIANT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xb3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, FilePathName);
		return result;
	}
	CString IGetConfigurationNames(LPCTSTR FilePathName, long Count)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0xb4, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, FilePathName, Count);
		return result;
	}
	LPDISPATCH GetPreviewBitmap(LPCTSTR FilePathName, LPCTSTR ConfigName)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xb5, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, FilePathName, ConfigName);
		return result;
	}
	CString GetExecutablePath()
	{
		CString result;
		InvokeHelper(0xb6, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long GetEdition()
	{
		long result;
		InvokeHelper(0xb7, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MoveDocument(LPCTSTR SourceDoc, LPCTSTR DestDoc, VARIANT& FromChildren, VARIANT& ToChildren, long Option)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_VARIANT VTS_VARIANT VTS_I4 ;
		InvokeHelper(0xb8, DISPATCH_METHOD, VT_I4, (void*)&result, parms, SourceDoc, DestDoc, &FromChildren, &ToChildren, Option);
		return result;
	}
	long CopyDocument(LPCTSTR SourceDoc, LPCTSTR DestDoc, VARIANT& FromChildren, VARIANT& ToChildren, long Option)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_VARIANT VTS_VARIANT VTS_I4 ;
		InvokeHelper(0xb9, DISPATCH_METHOD, VT_I4, (void*)&result, parms, SourceDoc, DestDoc, &FromChildren, &ToChildren, Option);
		return result;
	}
	long IMoveDocument(LPCTSTR SourceDoc, LPCTSTR DestDoc, long ChildCount, BSTR * FromChildren, BSTR * ToChildren, long Option)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_I4 VTS_PBSTR VTS_PBSTR VTS_I4 ;
		InvokeHelper(0xba, DISPATCH_METHOD, VT_I4, (void*)&result, parms, SourceDoc, DestDoc, ChildCount, FromChildren, ToChildren, Option);
		return result;
	}
	long ICopyDocument(LPCTSTR SourceDoc, LPCTSTR DestDoc, long ChildCount, BSTR * FromChildren, BSTR * ToChildren, long Option)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_I4 VTS_PBSTR VTS_PBSTR VTS_I4 ;
		InvokeHelper(0xbb, DISPATCH_METHOD, VT_I4, (void*)&result, parms, SourceDoc, DestDoc, ChildCount, FromChildren, ToChildren, Option);
		return result;
	}
	long AddToolbar4(long Cookie, LPCTSTR Title, LPCTSTR SmallBitmapImage, LPCTSTR LargeBitmapImage, long MenuPositionForToolbar, long DocumentType)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 ;
		InvokeHelper(0xbc, DISPATCH_METHOD, VT_I4, (void*)&result, parms, Cookie, Title, SmallBitmapImage, LargeBitmapImage, MenuPositionForToolbar, DocumentType);
		return result;
	}
	CString GetActiveConfigurationName(LPCTSTR FilePathName)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xbd, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, FilePathName);
		return result;
	}
	VARIANT Command(long Command, VARIANT& Args)
	{
		VARIANT result;
		static BYTE parms[] = VTS_I4 VTS_VARIANT ;
		InvokeHelper(0xbe, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, Command, &Args);
		return result;
	}
	VARIANT GetRecentFiles()
	{
		VARIANT result;
		InvokeHelper(0xbf, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void ShowBubbleTooltip(long PointAt, LPCTSTR FlashButtonIDs, long TitleResID, LPCTSTR TitleString, LPCTSTR MessageString)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xc0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, PointAt, FlashButtonIDs, TitleResID, TitleString, MessageString);
	}
	CString GetMaterialSchemaPathName()
	{
		CString result;
		InvokeHelper(0xc1, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	VARIANT GetMaterialDatabases()
	{
		VARIANT result;
		InvokeHelper(0xc2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	long GetMaterialDatabaseCount()
	{
		long result;
		InvokeHelper(0xc3, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	CString IGetMaterialDatabases(long Count)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xc4, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, Count);
		return result;
	}
	LPDISPATCH CreateTaskpaneView(long * Bitmap, LPCTSTR ToolTip, LPDISPATCH PHandler)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_PI4 VTS_BSTR VTS_DISPATCH ;
		InvokeHelper(0xc5, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Bitmap, ToolTip, PHandler);
		return result;
	}
	void ShowBubbleTooltipAt(long PointX, long PointY, long ArrowPos, LPCTSTR TitleString, LPCTSTR MessageString, LPCTSTR UrlLoc)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xc6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, PointX, PointY, ArrowPos, TitleString, MessageString, UrlLoc);
	}
	void InstallQuickTipGuide(LPDISPATCH PInterface)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0xc7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, PInterface);
	}
	void UnInstallQuickTipGuide(LPDISPATCH PInterface)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0xc8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, PInterface);
	}
	void RefreshQuickTipWindow()
	{
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long GetLastToolbarID()
	{
		long result;
		InvokeHelper(0xca, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH CreatePMPage(long DialogId, LPCTSTR Title, LPDISPATCH Handler)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_DISPATCH ;
		InvokeHelper(0xcb, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, DialogId, Title, Handler);
		return result;
	}
	long GetUserTypeLibReferenceCount()
	{
		long result;
		InvokeHelper(0xcc, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	VARIANT get_UserTypeLibReferences()
	{
		VARIANT result;
		InvokeHelper(0xcd, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_UserTypeLibReferences(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xcd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}
	CString IGetUserTypeLibReferences(long NCount)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xce, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, NCount);
		return result;
	}
	void ISetUserTypeLibReferences(long NCount, BSTR * BstrTlbRef)
	{
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0xcf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, NCount, BstrTlbRef);
	}
	BOOL RemoveUserTypeLibReferences(VARIANT& VTlbRef)
	{
		BOOL result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xd0, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, &VTlbRef);
		return result;
	}
	BOOL IRemoveUserTypeLibReferences(long NCount, BSTR * BstrTlbRef)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0xd1, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, NCount, BstrTlbRef);
		return result;
	}
	BOOL get_UserControlBackground()
	{
		BOOL result;
		InvokeHelper(0xd2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_UserControlBackground(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xd2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString GetOpenFileName(LPCTSTR DialogTitle, LPCTSTR InitialFileName, LPCTSTR FileFilter, long * OpenOptions, BSTR * ConfigName, BSTR * DisplayName)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_PI4 VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0xd3, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, DialogTitle, InitialFileName, FileFilter, OpenOptions, ConfigName, DisplayName);
		return result;
	}
	void ShowTooltip(LPCTSTR ToolbarName, long ButtonID, long SelectIDMask1, long SelectIDMask2, LPCTSTR TitleString, LPCTSTR MessageString)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xd4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ToolbarName, ButtonID, SelectIDMask1, SelectIDMask2, TitleString, MessageString);
	}
	BOOL AddMenuItem3(long DocumentType, long Cookie, LPCTSTR MenuItem, long Position, LPCTSTR MenuCallback, LPCTSTR MenuEnableMethod, LPCTSTR HintString, LPCTSTR BitmapFilePath)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xd5, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, DocumentType, Cookie, MenuItem, Position, MenuCallback, MenuEnableMethod, HintString, BitmapFilePath);
		return result;
	}
	long GetLatestSupportedFileVersion()
	{
		long result;
		InvokeHelper(0xd6, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	void GetOpenedFileInfo(BSTR * FileName, long * Options)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0xd7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName, Options);
	}
	LPDISPATCH GetOpenDocument(LPCTSTR DocName)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xd8, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, DocName);
		return result;
	}
	LPDISPATCH GetImportFileData(LPCTSTR FileName)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xd9, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, FileName);
		return result;
	}
	BOOL LoadFile3(LPCTSTR FileName, LPCTSTR ArgString, LPDISPATCH ImportData)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_DISPATCH ;
		InvokeHelper(0xda, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, FileName, ArgString, ImportData);
		return result;
	}
	LPDISPATCH CreateTaskpaneView2(LPCTSTR Bitmap, LPCTSTR ToolTip)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xdb, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Bitmap, ToolTip);
		return result;
	}
	LPDISPATCH GetCommandManager(long Cookie)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xdc, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Cookie);
		return result;
	}
	void DragToolbarButton(long SourceToolbar, long TargetToolbar, long SourceIndex, long TargetIndex)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0xdd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, SourceToolbar, TargetToolbar, SourceIndex, TargetIndex);
	}
	void AddCallback(long Cookie, LPCTSTR CallbackFunction)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0xde, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Cookie, CallbackFunction);
	}
	void RemoveCallback(long Cookie)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xdf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Cookie);
	}
	void ShowHelp(LPCTSTR HelpFile, long HelpTopic)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0xe0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, HelpFile, HelpTopic);
	}
	long GetErrorMessages(VARIANT * Msgs, VARIANT * MsgIDs, VARIANT * MsgTypes)
	{
		long result;
		static BYTE parms[] = VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0xe1, DISPATCH_METHOD, VT_I4, (void*)&result, parms, Msgs, MsgIDs, MsgTypes);
		return result;
	}
	CString GetCurrentMacroPathFolder()
	{
		CString result;
		InvokeHelper(0xe2, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH LoadFile4(LPCTSTR FileName, LPCTSTR ArgString, LPDISPATCH ImportData, long * Errors)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_DISPATCH VTS_PI4 ;
		InvokeHelper(0xe3, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, FileName, ArgString, ImportData, Errors);
		return result;
	}
	BOOL get_CommandInProgress()
	{
		BOOL result;
		InvokeHelper(0xe4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_CommandInProgress(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xe4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL CloseAllDocuments(BOOL IncludeUnsaved)
	{
		BOOL result;
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xe5, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, IncludeUnsaved);
		return result;
	}
	long GetCommandID(LPCTSTR Clsid, long UserCmdID)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0xe6, DISPATCH_METHOD, VT_I4, (void*)&result, parms, Clsid, UserCmdID);
		return result;
	}
	BOOL PreviewDocx64(__int64 * HWnd, LPCTSTR FullName)
	{
		BOOL result;
		static BYTE parms[] = VTS_PI8 VTS_BSTR ;
		InvokeHelper(0xe7, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, HWnd, FullName);
		return result;
	}
	BOOL get_TaskPaneIsPinned()
	{
		BOOL result;
		InvokeHelper(0xe8, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_TaskPaneIsPinned(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xe8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL GetUserProgressBar(LPDISPATCH * PProgressBar)
	{
		BOOL result;
		static BYTE parms[] = VTS_PDISPATCH ;
		InvokeHelper(0xe9, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, PProgressBar);
		return result;
	}
	BOOL AddFileOpenItem3(long Cookie, LPCTSTR MethodName, LPCTSTR Description, LPCTSTR Extension, LPCTSTR OptionLabel, LPCTSTR OptionMethodName)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xea, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Cookie, MethodName, Description, Extension, OptionLabel, OptionMethodName);
		return result;
	}
	long GetCookie(LPCTSTR AddinClsid, long ResourceModuleHandle, LPDISPATCH AddinCallbacks)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_DISPATCH ;
		InvokeHelper(0xeb, DISPATCH_METHOD, VT_I4, (void*)&result, parms, AddinClsid, ResourceModuleHandle, AddinCallbacks);
		return result;
	}
	BOOL ActivateTaskPane(long TaskPaneID)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xec, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, TaskPaneID);
		return result;
	}
	LPDISPATCH GetExportFileData(long FileType)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xed, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, FileType);
		return result;
	}
	BOOL RemoveFromMenu(long CommandID, long DocumentType, long Option, BOOL RemoveParentMenu)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_BOOL ;
		InvokeHelper(0xee, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, CommandID, DocumentType, Option, RemoveParentMenu);
		return result;
	}
	BOOL RemoveFromPopupMenu(long CommandID, long DocumentType, long SelectionType, BOOL RemoveParentMenu)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_BOOL ;
		InvokeHelper(0xef, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, CommandID, DocumentType, SelectionType, RemoveParentMenu);
		return result;
	}
	CString GetMenuStrings(long CommandID, long DocumentType, BSTR * ParentMenuName)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0xf0, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, CommandID, DocumentType, ParentMenuName);
		return result;
	}
	void RefreshTaskpaneContent()
	{
		InvokeHelper(0xf1, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL PresetNewDrawingParameters(LPCTSTR DrawingTemplate, BOOL ShowTemplate, double Width, double Height)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BOOL VTS_R8 VTS_R8 ;
		InvokeHelper(0xf2, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, DrawingTemplate, ShowTemplate, Width, Height);
		return result;
	}
	void ResetPresetDrawingParameters()
	{
		InvokeHelper(0xf3, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL GetDocumentVisible(long Type)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xf4, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Type);
		return result;
	}
	BOOL RunCommand(long CommandID, LPCTSTR NewTitle)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0xf5, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, CommandID, NewTitle);
		return result;
	}
	LPDISPATCH get_JournalManager()
	{
		LPDISPATCH result;
		InvokeHelper(0xf6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void HideBubbleTooltip()
	{
		InvokeHelper(0xf7, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	LPDISPATCH GetOpenDocSpec(LPCTSTR FileName)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xf8, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, FileName);
		return result;
	}
	LPDISPATCH OpenDoc7(LPDISPATCH Specification)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0xf9, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Specification);
		return result;
	}
	BOOL BlockSkinning()
	{
		BOOL result;
		InvokeHelper(0xfa, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL ResumeSkinning()
	{
		BOOL result;
		InvokeHelper(0xfb, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void SetMultipleFilenamesPrompt(VARIANT& FileName)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xfc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &FileName);
	}
	BOOL GetPreviewBitmapFile(LPCTSTR DocumentPath, LPCTSTR ConfigName, LPCTSTR BitMapFile)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xfd, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, DocumentPath, ConfigName, BitMapFile);
		return result;
	}
	long DragToolbarButtonFromCommandID(long CommandID, long TargetToolbar, long TargetIndex)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0xfe, DISPATCH_METHOD, VT_I4, (void*)&result, parms, CommandID, TargetToolbar, TargetIndex);
		return result;
	}
	long AddMenuItem4(long DocumentType, long Cookie, LPCTSTR MenuItem, long Position, LPCTSTR MenuCallback, LPCTSTR MenuEnableMethod, LPCTSTR HintString, LPCTSTR BitmapFilePath)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xff, DISPATCH_METHOD, VT_I4, (void*)&result, parms, DocumentType, Cookie, MenuItem, Position, MenuCallback, MenuEnableMethod, HintString, BitmapFilePath);
		return result;
	}
	long AddMenuPopupItem3(long DocumentType, long Cookie, long SelectType, LPCTSTR PopupItemName, LPCTSTR MenuCallback, LPCTSTR MenuEnableMethod, LPCTSTR HintString, LPCTSTR CustomNames)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x100, DISPATCH_METHOD, VT_I4, (void*)&result, parms, DocumentType, Cookie, SelectType, PopupItemName, MenuCallback, MenuEnableMethod, HintString, CustomNames);
		return result;
	}
	void GetBuildNumbers(BSTR * BaseVersion, BSTR * CurrentVersion)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0x101, DISPATCH_METHOD, VT_EMPTY, NULL, parms, BaseVersion, CurrentVersion);
	}
	void put_FrameLeft(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x102, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_FrameLeft()
	{
		long result;
		InvokeHelper(0x102, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_FrameTop(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x103, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_FrameTop()
	{
		long result;
		InvokeHelper(0x103, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_FrameWidth(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x104, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_FrameWidth()
	{
		long result;
		InvokeHelper(0x104, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_FrameHeight(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x105, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_FrameHeight()
	{
		long result;
		InvokeHelper(0x105, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_FrameState(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x106, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_FrameState()
	{
		long result;
		InvokeHelper(0x106, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	long RegisterTrackingDefinition(LPCTSTR Name)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x107, DISPATCH_METHOD, VT_I4, (void*)&result, parms, Name);
		return result;
	}
	BOOL SetNewFilename(LPCTSTR FileName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x108, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, FileName);
		return result;
	}
	void put_EnableFileMenu(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x109, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_EnableFileMenu()
	{
		BOOL result;
		InvokeHelper(0x109, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	CString GetCurrentFileUser(LPCTSTR FilePathName)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x10a, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, FilePathName);
		return result;
	}
	VARIANT GetMacroMethods(LPCTSTR FilePathName, long Filter)
	{
		VARIANT result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x10b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, FilePathName, Filter);
		return result;
	}
	void EnablePhotoWorksProgressiveRender(BOOL BEnable)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x10c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, BEnable);
	}
	BOOL RunAttachedMacro(LPCTSTR FileName, LPCTSTR ModuleName, LPCTSTR ProcedureName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x10d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, FileName, ModuleName, ProcedureName);
		return result;
	}
	BOOL RunMacro2(LPCTSTR FilePathName, LPCTSTR ModuleName, LPCTSTR ProcedureName, long Options, long * Error)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0x10e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, FilePathName, ModuleName, ProcedureName, Options, Error);
		return result;
	}
	BOOL IsCommandEnabled(long CommandID)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x10f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, CommandID);
		return result;
	}
	long GetDocumentCount()
	{
		long result;
		InvokeHelper(0x110, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	VARIANT GetDocuments()
	{
		VARIANT result;
		InvokeHelper(0x111, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH IGetDocuments(long NumDocuments)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x112, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, NumDocuments);
		return result;
	}
	LPDISPATCH GetModelView(LPCTSTR ModelName, long WindowID, long Row, long Column)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x113, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, ModelName, WindowID, Row, Column);
		return result;
	}
	long ResetUntitledCount(long PartValue, long AssemValue, long DrawingValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x114, DISPATCH_METHOD, VT_I4, (void*)&result, parms, PartValue, AssemValue, DrawingValue);
		return result;
	}
	BOOL GetToolbarVisibility(long Toolbar)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x115, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Toolbar);
		return result;
	}
	void SetToolbarVisibility(long Toolbar, BOOL Visibility)
	{
		static BYTE parms[] = VTS_I4 VTS_BOOL ;
		InvokeHelper(0x116, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Toolbar, Visibility);
	}
	VARIANT GetLastSaveError(VARIANT * FilePath, VARIANT * ErrorCode)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x117, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, FilePath, ErrorCode);
		return result;
	}
	long RegisterThirdPartyPopupMenu()
	{
		long result;
		InvokeHelper(0x118, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	BOOL AddItemToThirdPartyPopupMenu(long RegisterId, long DocType, LPCTSTR Item, LPCTSTR CallbackFcnAndModule, LPCTSTR CustomName, LPCTSTR HintString, LPCTSTR BitmapFileName, long MenuItemTypeOption)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 ;
		InvokeHelper(0x119, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, RegisterId, DocType, Item, CallbackFcnAndModule, CustomName, HintString, BitmapFileName, MenuItemTypeOption);
		return result;
	}
	BOOL ShowThirdPartyPopupMenu(long RegisterId, long Posx, long Posy)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x11a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, RegisterId, Posx, Posy);
		return result;
	}
	long IsSame(LPDISPATCH Object1, LPDISPATCH Object2)
	{
		long result;
		static BYTE parms[] = VTS_DISPATCH VTS_DISPATCH ;
		InvokeHelper(0x11b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, Object1, Object2);
		return result;
	}
	BOOL GetButtonPosition(long PointAt, long * LocX, long * LocY)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x11c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, PointAt, LocX, LocY);
		return result;
	}
	BOOL RunJournalCmd(LPCTSTR Cmd)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x11d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Cmd);
		return result;
	}
	BOOL SetThirdPartyPopupMenuState(long RegisterId, BOOL IsActive)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BOOL ;
		InvokeHelper(0x11e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, RegisterId, IsActive);
		return result;
	}
	void put_EnableBackgroundProcessing(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x11f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_EnableBackgroundProcessing()
	{
		BOOL result;
		InvokeHelper(0x11f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL IsBackgroundProcessingCompleted(LPCTSTR FilePath)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x120, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, FilePath);
		return result;
	}
	void ShowBubbleTooltipAt2(long PointX, long PointY, long ArrowPos, LPCTSTR TitleString, LPCTSTR MessageString, long TitleBitmapID, LPCTSTR TitleBitmap, LPCTSTR UrlLoc, long Cookie, long LinkStringID, LPCTSTR LinkString, LPCTSTR CallBack)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_I4 VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x121, DISPATCH_METHOD, VT_EMPTY, NULL, parms, PointX, PointY, ArrowPos, TitleString, MessageString, TitleBitmapID, TitleBitmap, UrlLoc, Cookie, LinkStringID, LinkString, CallBack);
	}
	BOOL RemoveItemFromThirdPartyPopupMenu(long RegisterId, long DocType, LPCTSTR Item, long IconIndex)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_I4 ;
		InvokeHelper(0x122, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, RegisterId, DocType, Item, IconIndex);
		return result;
	}

	// ISldWorks 属性
public:

};
