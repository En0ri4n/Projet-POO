#include "Projet.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    ProjetPOO::Projet form;
    Application::Run(% form);
}