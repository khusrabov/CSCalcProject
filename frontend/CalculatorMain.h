#ifndef CALCULATORMAIN_H
#define CALCULATORMAIN_H

#include "../backend/RequestHandler.hpp"

//(*Headers(CalculatorFrame)
#include <wx/filename.h>
#include <wx/stdpaths.h>
#include <wx/wx.h>
//*)

class CalculatorFrame : public wxFrame {
 public:
  CalculatorFrame();

  void OnExit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);
  void OnButton(wxCommandEvent& event);
  void OnPaint(wxPaintEvent& event);

 private:
  RequestHandler rh;

  wxStaticText* MainOutputWindow;
  wxStaticText* Reg0;
  wxStaticText* Reg1;
  wxStaticText* Reg2;
  wxStaticText* Reg3;
  wxStaticText* Reg4;
  wxStaticText* Reg5;
  wxStaticText* Reg6;
  wxStaticText* Reg7;
  wxStaticText* CBuff1;
  wxStaticText* CBuff2;
  wxStaticText* CBuff3;
  wxStaticText* CBuff4;
  wxStaticText* CBuff5;
  wxStaticText* CBuff6;

  wxString pics_location;
  wxDECLARE_EVENT_TABLE();
};

#endif  // CALCULATORMAIN_H
