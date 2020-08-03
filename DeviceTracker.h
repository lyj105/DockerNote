 
/*--------------------------------------------------------------------------------------------------------------------------------------
 |  Copyright(c) 2019-2020 Company Name 
 |  All rights reserved. 
 |   
 |  file name: DeviceTracker.h
 |  breif	 : 
 |   
 |  version  : 1.0
 |  author 	 : bidboy
 |  times	 : 2019-7-20
 |  other	 : ...
 --------------------------------------------------------------------------------------------------------------------------------------*/
  #ifndef _DEVICETRACKER_H_
  #define _DEVICETRACKER_H_
 /*------------------------------------------------------------------------------------------------------------------------------------*
  |		includes:																													   |
  *------------------------------------------------------------------------------------------------------------------------------------*/
#include <zent.h>
#include <NDISupLib.h>
#include <bsstkObject.h>
#include <bsstkView3D.h>
#include <bsstkTracker.h>
#include <bsstkSTLActor.h>
#include <bsstkAxesActor.h>
#include <bsstkAngleActor.h>
#include <bsstkDicomViewMrg.h>
#include <FL/Fl_Double_Window.H>
#include <bsstkToolLine2DActor.h>
#include <bsstkToolLine3DActor.h>
#include <ActorDataMrg.h>

 /*------------------------------------------------------------------------------------------------------------------------------------*
  |		declare data type:																											   |
  *------------------------------------------------------------------------------------------------------------------------------------*/
class CZentLogic;

 /*------------------------------------------------------------------------------------------------------------------------------------*
  |		static function:																											   |
  *------------------------------------------------------------------------------------------------------------------------------------*/
 
 
 /*------------------------------------------------------------------------------------------------------------------------------------*
  |		declare constant variables:																									   |
  *------------------------------------------------------------------------------------------------------------------------------------*/
  
  
 /*------------------------------------------------------------------------------------------------------------------------------------*
  |		external variables:																											   |
  *------------------------------------------------------------------------------------------------------------------------------------*/
  

 /*------------------------------------------------------------------------------------------------------------------------------------*
  |		macro methods:																												   |
  *------------------------------------------------------------------------------------------------------------------------------------*/
 
 
 /*------------------------------------------------------------------------------------------------------------------------------------*
  |		class methods:																												   |
  *------------------------------------------------------------------------------------------------------------------------------------*/


#pragma once

/*!
 * Copyright (C) 2019, Chongqing Bosscom Science&Technology Co.,Ltd.
 * All rights reserved.
 *
 * \file     CDeviceTracker.h
 * \brief    The header file for doxygen cpp comment style demo.
 * \date     2019-12-3
 * \author   sh
 * \author   another,author,...
 */
#ifndef _DEVICETRACKEREX_H_
#define _DEVICETRACKEREX_H_

#include <zent.h>
#include <NDISupLib.h>
#include <bsstkObject.h>
#include <bsstkView3D.h>
#include <bsstkTracker.h>
#include <bsstkSTLActor.h>
#include <bsstkAxesActor.h>
#include <bsstkAngleActor.h>
#include <bsstkDicomViewMrg.h>
#include <FL/Fl_Double_Window.H>
#include <bsstkToolLine2DActor.h>
#include <bsstkToolLine3DActor.h>
#include <ActorDataMrg.h>

class CZentLogic;

BSSTKEventMacroPayLoad(NDIToolRemoveEvent, UserEvent, std::string)
class CDeviceTracker
	:public bsstk::CObject
{
private:
	typedef bsstk::CMemberCommand<CDeviceTracker>	NDIObserver;
public:
	CDeviceTracker();
	~CDeviceTracker();
public:
    /**
        \brief Navigation device connection status false.
               bug : 154
    */
    bool getConnectState()const;
public:
	bool ConnectDevice();
	bool InitObject(CZentLogic*);
	void ToolFreezing(bool bstate);
	void ShowTool(std::string sToolKey);
	void HideTool(std::string sToolKey);
	void SetSelectToolKey(const std::string& tool);
	void SetDynamicDistance(bool bOpen);
	void ResetRenderTrackerToolStatus();
	void SetAllToosExtendedLineVisible(bool bVisible);
	void SetSelectPoints(std::vector<bsstk::CPointType>);
	void SetRegisTransform(const bsstk::CTransform transform);
	void SetComputeTransform(ndi::NDI_Device_Type type, const bsstk::CTransform transform);
public:
	bool ToolFreezing()const;
	std::string GetSelelctToolKey();
	float GetDynamicDistanceOnTool(void);
	bool GetDynamicDistanceOnSwitch(void)const;
	bool GetRenderTrackerTools(void)const;
	bool GetAllToosExtendedLineVisible()const;
	std::vector<std::string>& GetShowToolRecorder();
	std::vector<std::string>& GetHideToolRecorder();
protected:
	void __ClearDynamicDistance();
	int _InitRegisterMethon(bsstk::CTransform transform, ndi::NDI_Device_Type type);
	void _InitBssPoint(ndi::NDI_Device_Type type);
	bool _InitQuoteExternalObject(CZentLogic*);
	bool _InitObserverEventObject();
	bool _InitSurgicalBagToolResources();
	void _AutoSelectTool();
private:
	void AuroraTrackerMsg(const bsstk::CObject* caller, const bsstk::CEventObject& event);
	void PolarisTrackerMsg(const bsstk::CObject* caller, const bsstk::CEventObject& event);
	void DeviceTrackerMsg(const bsstk::CObject* caller, const bsstk::CEventObject& event);
protected:
	CNDISupLib*			m_nidAurora;
	CNDISupLib*			m_nidPolaris;
	NDIObserver*		m_pAuroraObserver;
	NDIObserver*		m_pPolarisObserver;
protected:
	/** 导航的空间匹配数据 */
	bsstk::CTransform _AuroraTransform;
	bsstk::CTransform _PolarisTransform;
	/** 注册矩阵 */
	bsstk::CTransform _registransform;
	/** 选择点矩阵 */
	bsstk::CTransform _selToolTransform;
	/** 选择的三个点 */
	std::vector<bsstk::CPointType> _vSelectPoints;
	/** 参考架工具数据 */
	ToolAttribute _toolReferenceFrameData;
	/** 当前选中的导航工具 */
	std::string m_curSelToolKey;
	/** 冻结工具flag */
	bool m_bFreezeTools;
	/** 工具延长线显示 */
	bool _bShowToolExtended;
protected:
	/** 注册可拆卸参考架注册flag */
	std::atomic<bool> _bInitAuroraRemovable;
	std::atomic<bool> _bInitPolarisRemovable;
	std::atomic_flag _atomic_lock;
protected:
	/** 动态测距 */
	std::string _curDynamicDistanceToolKey;
	std::atomic_bool _bDynamicDistance;
	bsstk::CPointType _firstRecordPoint;
protected:
    std::atomic_bool _bConnectDeviceOk;
    std::atomic_int _init_flag;
    std::atomic_bool _bStopNdiThread;
	std::atomic_bool _bRenderTrackerTools;
	std::vector<std::string> vShowToolRecorder;
	std::vector<std::string> vHideToolRecorder;
	std::vector<ToolAttribute> m_vBufferToolContainers;
private:
	CActorDataMrg* _pQuoteExternalActorMrg;
	CZentLogic* _pQuoteExternalZentLogic;
};

#endif	/// !_DEVICETRACKEREX_H_


#endif
