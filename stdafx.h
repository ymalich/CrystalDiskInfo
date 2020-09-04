﻿// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif

#ifndef WINVER
#define WINVER 0x0501
#endif

#ifndef _WIN32_WINNT              
#define _WIN32_WINNT 0x0501
#endif						

#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS 0x0410
#endif

#ifndef _WIN32_IE
#define _WIN32_IE 0x0600
#endif

#define _AFX_NO_MFC_CONTROLS_IN_DIALOGS
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC core and standard component
#include <afxext.h>         // Extended MFC

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>		// MFC IE4 Common Control support
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC Windows Common Control support
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxdhtml.h>			// HTML Dialogs

#include "DHtmlDialogEx.h"		// CDHtmlDialogEx by hiyohiyo
#include "DHtmlMainDialog.h"	// CDHtmlMainDialog by hiyohiyo

#include <comutil.h>
#include <memory>
#include <vector>

#include "CommonFx.h"
#include "UtilityFx.h"

#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#pragma warning(disable : 4996)

//------------------------------------------------
// Option Flags
//------------------------------------------------

// For Task Tray Icon Feature
#define OPTION_TASK_TRAY

//------------------------------------------------
// Global Sttings
//------------------------------------------------

// Version Information
#define PROJECT_NAME			_T("CrystalDiskInfo")
#define PRODUCT_NAME			_T("CrystalDiskInfo")

#if KUREI_KEI_SUPPORT
#define PRODUCT_SHORT_NAME		_T("CDI 8 KKE")

#ifdef _M_ARM
#define PRODUCT_EDITION			_T("Kurei Kei Edition ARM32")
#elif _M_ARM64
#define PRODUCT_EDITION			_T("Kurei Kei Edition ARM64")
#elif _M_X64
#define PRODUCT_EDITION			_T("Kurei Kei Edition x64")
#else
#define PRODUCT_EDITION			_T("Kurei Kei Edition")
#endif
#elif SUISHO_SHIZUKU_SUPPORT
#define PRODUCT_SHORT_NAME		_T("CDI 8 SE")
#ifdef _M_ARM32
#define PRODUCT_EDITION			_T("Shizuku Edition ARM32")
#elif _M_ARM64
#define PRODUCT_EDITION			_T("Shizuku Edition ARM64")
#elif _M_X64
#define PRODUCT_EDITION			_T("Shizuku Edition x64")
#else
#define PRODUCT_EDITION			_T("Shizuku Edition")
#endif
#else
#define PRODUCT_SHORT_NAME		_T("CDI 8")
#ifdef _M_ARM
#define PRODUCT_EDITION			_T("ARM32")
#elif _M_ARM64
#define PRODUCT_EDITION			_T("ARM64")
#elif _M_X64
#define PRODUCT_EDITION			_T("x64")
#else
#define PRODUCT_EDITION			_T("")
#endif
#endif

#define PRODUCT_VERSION				L"8.8.2"
#define PRODUCT_RELEASE				L"2020/09/01"
#define PRODUCT_COPY_YEAR			L"2008-2020"
#define PRODUCT_COPYRIGHT			L"© 2008-2020 hiyohiyo"
#define PRODUCT_LICENSE				L"The MIT License"

#define DEFAULT_FONT_FACE_1			L"Segoe UI"
#define DEFAULT_FONT_FACE_2			L"Tahoma"

#define THEME_DIR					L"CdiResource\\themes\\"
#define LANGUAGE_DIR				L"CdiResource\\language\\"

#define MENU_THEME_INDEX			3
#define MENU_LANG_INDEX				6

#define DEFAULT_THEME				L"Default"
#define DEFAULT_LANGUAGE			L"English"

#define TIMER_UPDATE_DIALOG			500

#define URL_CRYSTAL_DEW_WORLD_JA	L"https://crystalmark.info/ja/"
#define URL_CRYSTAL_DEW_WORLD_EN 	L"https://crystalmark.info/en/"

#define	URL_PROJECT_SHIZUKU_JA		L"https://suishoshizuku.com/ja/"
#define	URL_PROJECT_SHIZUKU_EN		L"https://suishoshizuku.com/en/"

#define URL_PRONAMA	                L"http://pronama.jp/crystaldiskinfo"

#ifdef SUISHO_SHIZUKU_SUPPORT

#ifdef KUREI_KEI_SUPPORT
#define	URL_PROJECT_SITE_1		    L"http://pronama.jp/crystaldiskinfo"
#define URL_PROJECT_SITE_2		    L"http://pronama.jp/ixy"
#define URL_PROJECT_SITE_3	        L"http://pronama.jp/uesakasumire"
#define URL_PROJECT_SITE_4			L"http://pronama.jp/crystaldiskinfo"
#define URL_PROJECT_SITE_5			L""
#else
#define	URL_PROJECT_SITE_1		    L"http://kirinokasumu.com/"
#define URL_PROJECT_SITE_2		    L"http://linux-ha.sourceforge.jp/wp/"
#define URL_PROJECT_SITE_3	        L"http://ch.nicovideo.jp/oss"
#define URL_PROJECT_SITE_4			L"http://www.bellche.com/"
#define URL_PROJECT_SITE_5			L"https://suishoshizuku.com/"
#endif

#endif

#define	URL_VERSION_JA				L"https://crystalmark.info/ja/software/crystaldiskinfo/crystaldiskinfo-history/"
#define	URL_VERSION_EN				L"https://crystalmark.info/en/software/crystaldiskinfo/crystaldiskinfo-history/"
#define	URL_LICENSE_JA				L"https://crystalmark.info/ja/software/crystaldiskinfo/crystaldiskinfo-license/"
#define	URL_LICENSE_EN				L"https://crystalmark.info/en/software/crystaldiskinfo/crystaldiskinfo-license/"

#define URL_HTML_HELP_JA			L"https://crystalmark.info/ja/software/crystaldiskinfo/"
#define URL_HTML_HELP_EN 			L"https://crystalmark.info/en/software/crystaldiskinfo/"

// Command
static const int TRAY_TEMPERATURE_ICON_BASE = WM_APP + 0x1200;
static const int SELECT_DISK_BASE = WM_APP + 0x1300;
static const int AUTO_REFRESH_TARGET_BASE = WM_APP + 0x1400;
static const int SHOW_GRAPH_BASE = WM_APP + 0x1500;
static const int ALARM_SETTING_HEALTH_STATUS_BASE = WM_APP + 0x1900;
static const int ALARM_SETTING_TEMPERATURE_BASE = WM_APP + 0x2000; // Main Only
static const int GRAPH_DISK_INDEX = WM_APP + 0x2000; // Graph Only

static const int RE_EXEC = 5963;