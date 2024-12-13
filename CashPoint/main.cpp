#include <wx/wx.h>

#include "Record.hpp"
#include "MonLogic.h"

enum ID
{
	LOADED = 1,
	BUTTON_CLICKED_ID_TEN = 2,
	BUTTON_CLICKED_ID_TWENTY = 3,
	BUTTON_CLICKED_ID_FIFTY = 4,
	INPUTDATA = 5,
	WITHDRAW = 6,
	TRANSFER = 7
};

char status;
int AmountOfMoney;
Record::Camera cam;

class AppCode : public wxFrame
{
public:
	wxPanel* MainPanel = new wxPanel(this);
	wxButton* WithDraw = new wxButton(MainPanel, WITHDRAW, "Withdraw", wxPoint(350, 45), wxSize(120, 70));
	wxButton* Input = new wxButton(MainPanel, INPUTDATA, "Insert", wxPoint(350, 130), wxSize(120, 70));
	wxButton* Transfer = new wxButton(MainPanel, TRANSFER, "Transfer", wxPoint(350, 215), wxSize(120, 70));
	wxButton* TenMoney = new wxButton(MainPanel, BUTTON_CLICKED_ID_TEN, "£10", wxPoint(0, 12), wxSize(120, 70));
	wxButton* TwenMoney = new wxButton(MainPanel, BUTTON_CLICKED_ID_TWENTY, "£20", wxPoint(0, 147), wxSize(120, 70));
	wxButton* FieMoney = new wxButton(MainPanel, BUTTON_CLICKED_ID_FIFTY, "£50", wxPoint(0, 282), wxSize(120, 70));
	AppCode(const wxString& title) :wxFrame(nullptr, LOADED, title)
	{
		WithDraw->Show();
		Input->Show();
		Transfer->Show();
		TenMoney->Show(false);
		TwenMoney->Show(false);
		FieMoney->Show(false);
	}
private:
	void ChoiceW(wxCommandEvent& ev);
	void ChoiceI(wxCommandEvent& ev);
	void ChoiceT(wxCommandEvent& ev);
	void Ten(wxCommandEvent& ev);
	void Twenty(wxCommandEvent& ev);
	void Fifthty(wxCommandEvent& ev);
	wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(AppCode, wxFrame)
EVT_BUTTON(BUTTON_CLICKED_ID_TEN, AppCode::Ten)
EVT_BUTTON(WITHDRAW, AppCode::ChoiceW)
EVT_BUTTON(INPUTDATA, AppCode::ChoiceI)
EVT_BUTTON(BUTTON_CLICKED_ID_TWENTY, AppCode::Twenty)
EVT_BUTTON(BUTTON_CLICKED_ID_FIFTY, AppCode::Fifthty)
EVT_BUTTON(TRANSFER, AppCode::ChoiceT)
wxEND_EVENT_TABLE()

void AppCode::Ten(wxCommandEvent& ev)
{
	cam.TakePhoto("Captured.png");
	if ('W' == status)
	{
		AmountOfMoney = 10;
		char d[] = "hhi";
		SendDataToServer(d);
	}
}

void AppCode::Twenty(wxCommandEvent& ev)
{
	cam.TakePhoto("Captured.png");
	if ('W' == status)
	{
		AmountOfMoney = 20;
	}
}

void AppCode::Fifthty(wxCommandEvent& ev)
{
	cam.TakePhoto("Captured.png");
	if ('W' == status)
	{
		AmountOfMoney = 50;
		
	}
}

void AppCode::ChoiceW(wxCommandEvent& ev)
{
	status = 'W';
	AppCode::WithDraw->Show(false);
	AppCode::Input->Show(false);
	AppCode::Transfer->Show(false);
	AppCode::TenMoney->Show();
	AppCode::TwenMoney->Show();
	AppCode::FieMoney->Show();
}

void AppCode::ChoiceI(wxCommandEvent& ev)
{
	status = 'I';
	AppCode::WithDraw->Show(false);
	AppCode::Input->Show(false);
	AppCode::Transfer->Show(false);
	AppCode::TenMoney->Show();
	AppCode::TwenMoney->Show();
	AppCode::FieMoney->Show();
}

void AppCode::ChoiceT(wxCommandEvent& ev)
{
	status = 'T';
	AppCode::WithDraw->Show(false);
	AppCode::Input->Show(false);
	AppCode::Transfer->Show(false);
	AppCode::TenMoney->Show();
	AppCode::TwenMoney->Show();
	AppCode::FieMoney->Show();
}

class App : public wxApp
{
	bool OnInit()
	{
		AppCode* TheApp = new AppCode("CashPoint");
		TheApp->SetClientSize(800, 400);
		TheApp->Show();
		return true;
	}
};

wxIMPLEMENT_APP(App);