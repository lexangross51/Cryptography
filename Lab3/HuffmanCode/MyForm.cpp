#include "MyForm.h"
#include "Huffman.h"
#include "Hamming.h"
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(cli::array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    HuffmanCode::MyForm form;
    Application::Run(% form);
}