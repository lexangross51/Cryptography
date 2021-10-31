#pragma once

#include "Hamming.h"
#include <fstream>
#include <msclr\marshal_cppstd.h>

namespace HuffmanCode {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Сводка для MyForm3
	/// </summary>
	public ref class MyForm3 : public System::Windows::Forms::Form
	{
	public:
		MyForm3(Hamming *_ham)
		{
			InitializeComponent();
			ham = _ham;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm3()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		Hamming* ham;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RichTextBox^ richTextBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::RichTextBox^ richTextBox4;
	private: System::Windows::Forms::RichTextBox^ richTextBox5;
	private: System::Windows::Forms::Label^ label4;
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->richTextBox4 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox5 = (gcnew System::Windows::Forms::RichTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(16, 64);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(121, 46);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Закодировать текст\r\n";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm3::button2_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(150, 15);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(465, 98);
			this->richTextBox1->TabIndex = 5;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm3::richTextBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(16, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(121, 28);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Считать текст";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm3::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 148);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(121, 34);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Закодированный\r\nтекст\r\n";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(150, 148);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(465, 98);
			this->richTextBox2->TabIndex = 7;
			this->richTextBox2->Text = L"";
			this->richTextBox2->TextChanged += gcnew System::EventHandler(this, &MyForm3::richTextBox2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 269);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(205, 17);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Алфавит и его кодовые слова";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm3::label2_Click);
			// 
			// richTextBox3
			// 
			this->richTextBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox3->Location = System::Drawing::Point(19, 289);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(168, 214);
			this->richTextBox3->TabIndex = 10;
			this->richTextBox3->Text = L"";
			this->richTextBox3->TextChanged += gcnew System::EventHandler(this, &MyForm3::richTextBox3_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(444, 269);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(171, 17);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Проверочная матрица H";
			// 
			// richTextBox4
			// 
			this->richTextBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox4->Location = System::Drawing::Point(447, 289);
			this->richTextBox4->Name = L"richTextBox4";
			this->richTextBox4->Size = System::Drawing::Size(168, 130);
			this->richTextBox4->TabIndex = 12;
			this->richTextBox4->Text = L"";
			this->richTextBox4->TextChanged += gcnew System::EventHandler(this, &MyForm3::richTextBox4_TextChanged);
			// 
			// richTextBox5
			// 
			this->richTextBox5->Location = System::Drawing::Point(252, 289);
			this->richTextBox5->Name = L"richTextBox5";
			this->richTextBox5->Size = System::Drawing::Size(175, 214);
			this->richTextBox5->TabIndex = 13;
			this->richTextBox5->Text = L"";
			this->richTextBox5->TextChanged += gcnew System::EventHandler(this, &MyForm3::richTextBox5_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(249, 269);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(128, 17);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Полученные коды";
			// 
			// MyForm3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(645, 516);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->richTextBox5);
			this->Controls->Add(this->richTextBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm3";
			this->Text = L"Кодировщик";
			this->Load += gcnew System::EventHandler(this, &MyForm3::MyForm3_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


// Действия при загрузке формы
private: System::Void MyForm3_Load(System::Object^ sender, System::EventArgs^ e)
{
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
	richTextBox1->ReadOnly = true;
	richTextBox2->ReadOnly = true;
	richTextBox3->ReadOnly = true;
	richTextBox4->ReadOnly = true;
	richTextBox5->ReadOnly = true;
	button2->Enabled = false;
	ham->clearTable();

	// Выводим матрицу
	ham->readMatrix();
	std::ifstream matrix("matrixHam.txt");
	if (matrix.is_open())
	{
		std::string line, mat;
		getline(matrix, line);
		while (getline(matrix, line))
			mat += line + "\n";
		richTextBox4->Text = marshal_as<System::String^>(mat);
	}

	ham->readAlphabbet();
	// Выводим алфавит и кодовые слова
	std::ifstream alph("alphHam.txt");
	std::ifstream codes("codesHam.txt");
	if (alph.is_open() && codes.is_open())
	{
		std::string line1, line2, alphCodes;
		while (getline(alph, line1) && getline(codes, line2))
			alphCodes += line1 + "\t" + line2 + "\n";
		richTextBox3->Text = marshal_as<System::String^>(alphCodes);
	}

	ham->makeCodeHash();
	std::string codeHash = ham->getCodeHash();
	richTextBox5->Text = marshal_as<System::String^>(codeHash);
}

// Считать текст
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	ham->readText();
	richTextBox1->Text = File::ReadAllText("toencodeHam.txt");
	if (richTextBox1->Text != "")
	{
		button2->Enabled = true;
	}
	else
		MessageBox::Show("Файл с текстом пустой!");
}

// Кодируем текст
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	std::string encoded = ham->encode();
	richTextBox2->Text = marshal_as<System::String^>(encoded);
}

private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void richTextBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void richTextBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void richTextBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void richTextBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
