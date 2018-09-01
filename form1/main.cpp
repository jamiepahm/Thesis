#include "rgb_hsi_form.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	form1::rgb_hsi_form rgb_hsi;
	Application::Run(%rgb_hsi);
	return 0;
}