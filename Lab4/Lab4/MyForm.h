#pragma once

#include <fstream>
#include <string>
#include <msclr\marshal_cppstd.h>
#include "Vigenere.h"

using namespace std;

Vigenere v(26);
string text;
string encrypted;

namespace Lab4 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	using namespace System::IO;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;

	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::Label^ label2;


	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::RichTextBox^ richTextBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::RichTextBox^ richTextBox5;
	private: System::Windows::Forms::Label^ label1;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
	
	private: System::Windows::Forms::Button^ button4;

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->richTextBox4 = (gcnew System::Windows::Forms::RichTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->richTextBox5 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 43);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(139, 32);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Считать текст";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 81);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(446, 228);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(506, 81);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(219, 228);
			this->richTextBox2->TabIndex = 3;
			this->richTextBox2->Text = L"";
			this->richTextBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(502, 14);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(200, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Список ключевых слов";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(157, 43);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(114, 32);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Зашифровать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// richTextBox4
			// 
			this->richTextBox4->Location = System::Drawing::Point(12, 421);
			this->richTextBox4->Name = L"richTextBox4";
			this->richTextBox4->Size = System::Drawing::Size(446, 228);
			this->richTextBox4->TabIndex = 8;
			this->richTextBox4->Text = L"";
			this->richTextBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox4_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(8, 349);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(206, 20);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Зашифрованный текст";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(12, 382);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(123, 33);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Расшифровать";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(471, 395);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(214, 20);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Расшифрованный текст";
			// 
			// richTextBox5
			// 
			this->richTextBox5->Location = System::Drawing::Point(475, 421);
			this->richTextBox5->Name = L"richTextBox5";
			this->richTextBox5->Size = System::Drawing::Size(476, 228);
			this->richTextBox5->TabIndex = 11;
			this->richTextBox5->Text = L"";
			this->richTextBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox5_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(144, 20);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Исходный текст";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(506, 43);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(139, 32);
			this->button4->TabIndex = 14;
			this->button4->Text = L"Считать";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(961, 663);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->richTextBox5);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->richTextBox4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
		richTextBox1->ReadOnly = true;
		richTextBox2->ReadOnly = true;
		richTextBox4->ReadOnly = true;
		richTextBox5->ReadOnly = true;

		button3->Enabled = false;
		button2->Enabled = false;
		richTextBox4->Enabled = false;
		richTextBox5->Enabled = false;
	}
	
	// Считать текст из файла
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		ifstream in("text.txt");
		if (in.is_open())
		{
			string line;
			while (getline(in, line))
				text += line;
		}
		else
			MessageBox::Show("Невозможно открыть файл");

		richTextBox1->Text = File::ReadAllText("text.txt");

		if (richTextBox2->Text != "")
			button2->Enabled = true;
	}

	// Считать кллючевые слова из файла
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		vector<string> keywords;
		string keyword;
		ifstream in("keywords.txt");
		if (in.is_open())
		{
			while (in >> keyword)
				keywords.push_back(keyword);
			in.close();
		}
		else
			MessageBox::Show("Невозможно открыть файл!");

		v.setKeywords(keywords);
		richTextBox2->Text = File::ReadAllText("keywords.txt");

		if (richTextBox1->Text != "")
			button2->Enabled = true;
	}

	// Зашифровать текст
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (richTextBox1->Text != "" && richTextBox2->Text != "")
		{
			richTextBox4->Enabled = true;
			richTextBox5->Enabled = true;
			button3->Enabled = true;

			encrypted = v.encrypt(text);
			richTextBox4->Text = marshal_as<System::String^>(encrypted);
		}
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		string decrypted = v.decrypt(encrypted);
		richTextBox5->Text = marshal_as<System::String^>(decrypted);
	}


private: System::Void richTextBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void richTextBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void richTextBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

};
}
