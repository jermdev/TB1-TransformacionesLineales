#include "pch.h"
#include <iostream>
#include "FrmSimuladorTL.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew TB1TransformacionesLineales::FrmSimuladorTL());
	
}
