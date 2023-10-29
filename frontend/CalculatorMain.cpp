#include "CalculatorMain.h"

#include <wx/filename.h>
#include <wx/stdpaths.h>
#include <wx/wx.h>
//*)

enum {
  ID_BUTTON_0 = 0,
  ID_BUTTON_1 = 1,
  ID_BUTTON_2 = 2,
  ID_BUTTON_3 = 3,
  ID_BUTTON_4 = 4,
  ID_BUTTON_5 = 5,
  ID_BUTTON_6 = 6,
  ID_BUTTON_7 = 7,
  ID_BUTTON_8 = 8,
  ID_BUTTON_9 = 9,
  ID_BUTTON_10 = 10,
  ID_BUTTON_11 = 11,
  ID_BUTTON_12 = 12,
  ID_BUTTON_13 = 13,
  ID_BUTTON_14 = 14,
  ID_BUTTON_15 = 15,
  ID_BUTTON_16 = 16,
  ID_BUTTON_17 = 17,
  ID_BUTTON_18 = 18,
  ID_BUTTON_19 = 19,
  ID_BUTTON_20 = 20,
  ID_BUTTON_21 = 21,
  ID_BUTTON_22 = 22,
  ID_BUTTON_23 = 23,
  ID_BUTTON_24 = 24,
  ID_BUTTON_25 = 25,
  ID_BUTTON_26 = 26,
  ID_BUTTON_27 = 27,
  ID_BUTTON_28 = 28,
  ID_BUTTON_29 = 29,
  ID_BUTTON_30 = 30
};

CalculatorFrame::CalculatorFrame()
    : wxFrame(NULL, wxID_ANY, "Calculator", wxDefaultPosition,
              wxSize(640, 1000)) {
  // Set location of directory with pictures
  pics_location =
      wxFileName(wxStandardPaths::Get().GetExecutablePath()).GetPath() +
      wxT("/../frontend/pict");

  // Set background image
  wxBitmap main_window_bitmap(pics_location + wxT("/calcApp.png"),
                              wxBITMAP_TYPE_PNG);
  wxImage main_window_image = main_window_bitmap.ConvertToImage();
  wxBitmap main_window_resizedBitmap(main_window_image.Scale(572, 930));
  wxStaticBitmap* background =
      new wxStaticBitmap(this, wxID_ANY, main_window_resizedBitmap,
                         wxDefaultPosition, wxSize(572, 930));

  // Set an image for displaying memory registers
  // Load the image
  wxBitmap mem_display_bitmap(pics_location + wxT("/mem.png"),
                              wxBITMAP_TYPE_PNG);
  wxImage mem_display_image = mem_display_bitmap.ConvertToImage();
  wxBitmap mem_display_resized_bitmap(mem_display_image.Scale(881, 352));
  wxStaticBitmap* mem_display =
      new wxStaticBitmap(this, wxID_ANY, mem_display_resized_bitmap,
                         wxPoint(606, 399), wxSize(881, 352));

  // Create main output window
  MainOutputWindow = new wxStaticText(this, wxID_ANY, wxT("--------"),
                                wxPoint(62, 29), wxSize(483, 72));
  wxFont MainOutputWinowfont(43, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
  MainOutputWindow->SetFont(MainOutputWinowfont);
  MainOutputWindow->SetBackgroundColour(
      wxColour(0, 0, 0));  // Set background color to black
  MainOutputWindow->SetForegroundColour(
      wxColour(255, 0, 0));  // Set Text color to red

  // Create windows for displaying the rest of the numbers
  Reg0 = new wxStaticText(this, wxID_ANY, wxT("--------"), wxPoint(686, 680), wxSize(155,38));
  Reg1 = new wxStaticText(this, wxID_ANY, wxT("--------"), wxPoint(686, 640), wxSize(155,38));
  Reg2 = new wxStaticText(this, wxID_ANY, wxT("--------"), wxPoint(686, 600), wxSize(155,38));
  Reg3 = new wxStaticText(this, wxID_ANY, wxT("--------"), wxPoint(686, 560), wxSize(155,38));
  Reg4 = new wxStaticText(this, wxID_ANY, wxT("--------"), wxPoint(686, 520), wxSize(155,38));
  Reg5 = new wxStaticText(this, wxID_ANY, wxT("--------"), wxPoint(686, 480), wxSize(155,38));
  Reg6 = new wxStaticText(this, wxID_ANY, wxT("--------"), wxPoint(686, 440), wxSize(155,38));
  Reg7 = new wxStaticText(this, wxID_ANY, wxT("--------"), wxPoint(686, 400), wxSize(155,38));
  CBuff1 = new wxStaticText(this, wxID_ANY, wxT("--------"), wxPoint(900, 514), wxSize(155,38));
  CBuff2 = new wxStaticText(this, wxID_ANY, wxT("--------"), wxPoint(1079, 514), wxSize(155,38));
  CBuff3 = new wxStaticText(this, wxID_ANY, wxT("--------"), wxPoint(1258, 514), wxSize(155,38));
  CBuff4 = new wxStaticText(this, wxID_ANY, wxT("--------"), wxPoint(1277, 669), wxSize(155,38));
  CBuff5 = new wxStaticText(this, wxID_ANY, wxT("--------"), wxPoint(1098, 669), wxSize(155,38));
  CBuff6 = new wxStaticText(this, wxID_ANY, wxT("--------"), wxPoint(918, 669), wxSize(155,38));
  wxFont MemoryDisplayfont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
  Reg0->SetFont(MemoryDisplayfont);
  Reg0->SetForegroundColour(wxColour(0, 0, 0));  
  Reg1->SetFont(MemoryDisplayfont);
  Reg1->SetForegroundColour(wxColour(0, 0, 0));  
  Reg2->SetFont(MemoryDisplayfont);
  Reg2->SetForegroundColour(wxColour(0, 0, 0));  
  Reg3->SetFont(MemoryDisplayfont);
  Reg3->SetForegroundColour(wxColour(0, 0, 0));  
  Reg4->SetFont(MemoryDisplayfont);
  Reg4->SetForegroundColour(wxColour(0, 0, 0));  
  Reg5->SetFont(MemoryDisplayfont);
  Reg5->SetForegroundColour(wxColour(0, 0, 0));  
  Reg6->SetFont(MemoryDisplayfont);
  Reg6->SetForegroundColour(wxColour(0, 0, 0));  
  Reg7->SetFont(MemoryDisplayfont);
  Reg7->SetForegroundColour(wxColour(0, 0, 0));
  CBuff1->SetFont(MemoryDisplayfont);
  CBuff1->SetForegroundColour(wxColour(0, 0, 0)); 
  CBuff2->SetFont(MemoryDisplayfont);
  CBuff2->SetForegroundColour(wxColour(0, 0, 0)); 
  CBuff3->SetFont(MemoryDisplayfont);
  CBuff3->SetForegroundColour(wxColour(0, 0, 0)); 
  CBuff4->SetFont(MemoryDisplayfont);
  CBuff4->SetForegroundColour(wxColour(0, 0, 0)); 
  CBuff5->SetFont(MemoryDisplayfont);
  CBuff5->SetForegroundColour(wxColour(0, 0, 0));
  CBuff6->SetFont(MemoryDisplayfont);
  CBuff6->SetForegroundColour(wxColour(0, 0, 0));  
  


  // Set up buttons
  wxButton* button10 = new wxButton(this, ID_BUTTON_10, wxT("Turn"),
                                    wxPoint(41, 203), wxSize(70, 70), 0);
  wxBitmapButton* button11 = new wxBitmapButton(
      this, ID_BUTTON_11,
      wxBitmap(pics_location + wxT("/cx.png"), wxBITMAP_TYPE_PNG),
      wxPoint(41, 303), wxSize(70, 70));
  wxBitmapButton* button12 = new wxBitmapButton(
      this, ID_BUTTON_12,
      wxBitmap(pics_location + wxT("/p.png"), wxBITMAP_TYPE_PNG),
      wxPoint(164, 309), wxSize(70, 70));
  wxBitmapButton* button13 = new wxBitmapButton(
      this, ID_BUTTON_13,
      wxBitmap(pics_location + wxT("/x^y.png"), wxBITMAP_TYPE_PNG),
      wxPoint(252, 310), wxSize(70, 70));
  wxBitmapButton* button14 = new wxBitmapButton(
      this, ID_BUTTON_14,
      wxBitmap(pics_location + wxT("/swap.png"), wxBITMAP_TYPE_PNG),
      wxPoint(341, 421), wxSize(70, 70));
  wxBitmapButton* button15 = new wxBitmapButton(
      this, ID_BUTTON_15,
      wxBitmap(pics_location + wxT("/arrup.png"), wxBITMAP_TYPE_PNG),
      wxPoint(425, 419), wxSize(70, 70));
  wxBitmapButton* button16 = new wxBitmapButton(
      this, ID_BUTTON_16,
      wxBitmap(pics_location + wxT("/mult.png"), wxBITMAP_TYPE_PNG),
      wxPoint(341, 536), wxSize(70, 70));
  wxBitmapButton* button17 = new wxBitmapButton(
      this, ID_BUTTON_17,
      wxBitmap(pics_location + wxT("/plus.png"), wxBITMAP_TYPE_PNG),
      wxPoint(427, 536), wxSize(70, 70));
  wxBitmapButton* button18 = new wxBitmapButton(
      this, ID_BUTTON_18,
      wxBitmap(pics_location + wxT("/delen.png"), wxBITMAP_TYPE_PNG),
      wxPoint(339, 648), wxSize(70, 70));
  wxBitmapButton* button19 = new wxBitmapButton(
      this, ID_BUTTON_19,
      wxBitmap(pics_location + wxT("/minus.png"), wxBITMAP_TYPE_PNG),
      wxPoint(426, 649), wxSize(70, 70));

  wxBitmapButton* button7 = new wxBitmapButton(
      this, ID_BUTTON_7,
      wxBitmap(pics_location + wxT("/k7.png"), wxBITMAP_TYPE_PNG),
      wxPoint(61, 423), wxSize(70, 70));
  wxBitmapButton* button8 = new wxBitmapButton(
      this, ID_BUTTON_8,
      wxBitmap(pics_location + wxT("/k8.png"), wxBITMAP_TYPE_PNG),
      wxPoint(143, 423), wxSize(70, 70));
  wxBitmapButton* button9 = new wxBitmapButton(
      this, ID_BUTTON_9,
      wxBitmap(pics_location + wxT("/k9.png"), wxBITMAP_TYPE_PNG),
      wxPoint(225, 423), wxSize(70, 70));
  wxBitmapButton* button4 = new wxBitmapButton(
      this, ID_BUTTON_4,
      wxBitmap(pics_location + wxT("/k4.png"), wxBITMAP_TYPE_PNG),
      wxPoint(61, 536), wxSize(70, 70));
  wxBitmapButton* button5 = new wxBitmapButton(
      this, ID_BUTTON_5,
      wxBitmap(pics_location + wxT("/k5.png"), wxBITMAP_TYPE_PNG),
      wxPoint(144, 536), wxSize(70, 70));
  wxBitmapButton* button6 = new wxBitmapButton(
      this, ID_BUTTON_6,
      wxBitmap(pics_location + wxT("/k6.png"), wxBITMAP_TYPE_PNG),
      wxPoint(226, 536), wxSize(70, 70));
  wxBitmapButton* button1 = new wxBitmapButton(
      this, ID_BUTTON_1,
      wxBitmap(pics_location + wxT("/k1.png"), wxBITMAP_TYPE_PNG),
      wxPoint(61, 645), wxSize(70, 70));
  wxBitmapButton* button2 = new wxBitmapButton(
      this, ID_BUTTON_2,
      wxBitmap(pics_location + wxT("/k2.png"), wxBITMAP_TYPE_PNG),
      wxPoint(145, 645), wxSize(70, 70));
  wxBitmapButton* button3 = new wxBitmapButton(
      this, ID_BUTTON_3,
      wxBitmap(pics_location + wxT("/k3.png"), wxBITMAP_TYPE_PNG),
      wxPoint(227, 645), wxSize(70, 70));
  wxBitmapButton* button0 = new wxBitmapButton(
      this, ID_BUTTON_0,
      wxBitmap(pics_location + wxT("/k0.png"), wxBITMAP_TYPE_PNG),
      wxPoint(54, 777), wxSize(70, 70));

  wxBitmapButton* button20 = new wxBitmapButton(
      this, ID_BUTTON_20,
      wxBitmap(pics_location + wxT("/pnt.png"), wxBITMAP_TYPE_PNG),
      wxPoint(158, 777), wxSize(70, 70));
  wxBitmapButton* button21 = new wxBitmapButton(
      this, ID_BUTTON_21,
      wxBitmap(pics_location + wxT("/sign.png"), wxBITMAP_TYPE_PNG),
      wxPoint(262, 777), wxSize(70, 70));
  wxBitmapButton* button22 = new wxBitmapButton(
      this, ID_BUTTON_22,
      wxBitmap(pics_location + wxT("/vp.png"), wxBITMAP_TYPE_PNG),
      wxPoint(366, 777), wxSize(70, 70));
  wxBitmapButton* button23 = new wxBitmapButton(
      this, ID_BUTTON_23,
      wxBitmap(pics_location + wxT("/F.png"), wxBITMAP_TYPE_PNG),
      wxPoint(470, 777), wxSize(70, 70));
}

wxBEGIN_EVENT_TABLE(CalculatorFrame, wxFrame)
    EVT_BUTTON(wxID_ANY, CalculatorFrame::OnButton) 
wxEND_EVENT_TABLE()

void CalculatorFrame::OnButton(wxCommandEvent& event) {
  // s contains output: multiple values of registers
  // and circ_buff separated by "/"
  std::string s = rh.HandleReq(event.GetId());
  std::string delimiter = "/";

  // Parsing s. Kind of Python's Split("/")
  size_t pos = 0;
  std::vector<std::string> nums;
  while ((pos = s.find(delimiter)) != std::string::npos) {
    nums.push_back(s.substr(0, pos));
    s.erase(0, pos + delimiter.length());
  }

  this->MainOutputWindow->SetLabel(nums[0]);
  this->Reg0->SetLabel(nums[0]);
  this->Reg1->SetLabel(nums[1]);
  this->Reg2->SetLabel(nums[2]);
  this->Reg3->SetLabel(nums[3]);
  this->Reg4->SetLabel(nums[4]);
  this->Reg5->SetLabel(nums[5]);
  this->Reg6->SetLabel(nums[6]);
  this->Reg7->SetLabel(nums[7]);

  this->CBuff1->SetLabel(nums[8]);
  this->CBuff2->SetLabel(nums[9]);
  this->CBuff3->SetLabel(nums[10]);
  this->CBuff4->SetLabel(nums[11]);
  this->CBuff5->SetLabel(nums[12]);
  this->CBuff6->SetLabel(nums[13]);
}