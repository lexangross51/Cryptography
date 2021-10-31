#pragma once
#include"MyForm1.h"

namespace HuffmanCode {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(Huffman *_h)
		{
			InitializeComponent();
			h = _h;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ Избыточность;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::RichTextBox^ richTextBox3;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		Huffman* h;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->Избыточность = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(129, 31);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Считать текст";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(147, 12);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(411, 96);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm2::richTextBox1_TextChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 66);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(129, 42);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Декодировать \r\nтекст\r\n";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm2::button2_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(124, 358);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(149, 22);
			this->textBox3->TabIndex = 17;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm2::textBox3_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 358);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(94, 34);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Неравенство\r\nКрафта";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(124, 313);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(149, 22);
			this->textBox2->TabIndex = 15;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm2::textBox2_TextChanged);
			// 
			// Избыточность
			// 
			this->Избыточность->AutoSize = true;
			this->Избыточность->Location = System::Drawing::Point(9, 313);
			this->Избыточность->Name = L"Избыточность";
			this->Избыточность->Size = System::Drawing::Size(103, 17);
			this->Избыточность->TabIndex = 14;
			this->Избыточность->Text = L"Избыточность";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(124, 264);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(149, 22);
			this->textBox1->TabIndex = 13;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm2::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 264);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(109, 34);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Средняя длина\r\nкодового слова";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 140);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 34);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Декодированный\r\nтекст\r\n";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(147, 140);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(411, 96);
			this->richTextBox2->TabIndex = 19;
			this->richTextBox2->Text = L"";
			this->richTextBox2->TextChanged += gcnew System::EventHandler(this, &MyForm2::richTextBox2_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(647, 15);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(120, 34);
			this->label5->TabIndex = 21;
			this->label5->Text = L"Кодовые слова \r\nкаждого символа\r\n";
			// 
			// richTextBox3
			// 
			this->richTextBox3->Location = System::Drawing::Point(592, 64);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(175, 172);
			this->richTextBox3->TabIndex = 20;
			this->richTextBox3->Text = L"";
			this->richTextBox3->TextChanged += gcnew System::EventHandler(this, &MyForm2::richTextBox3_TextChanged);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 418);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->Избыточность);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Декодировщик";
			this->Text = L"Декодировщик";
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

void writeInfo()
{
	double averLenght = h->getAverageLenght();
	double red = h->getRedundancy();
	textBox1->Text = (String::Format("{0}", averLenght));
	textBox2->Text = (String::Format("{0}", red));
	bool kraft = h->KraftInequality();
	if (kraft)
		textBox3->Text = "Выполнено";
	else
		textBox3->Text = "Не выполнено";
}

// При загрузке формы вывести коды всех символов и инфу о средней длине, 
// избыточности и нер-ве Крафта
private: System::Void MyForm2_Load(System::Object^ sender, System::EventArgs^ e)
{
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
	richTextBox1->ReadOnly = true;
	richTextBox2->ReadOnly = true;
	richTextBox3->ReadOnly = true;
	textBox1->ReadOnly = true;
	textBox2->ReadOnly = true;
	textBox3->ReadOnly = true;

	richTextBox3->Text = File::ReadAllText("codes.txt");
	writeInfo();
	button2->Enabled = false;
}

// Кнопка - считать текст
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	richTextBox1->Text = File::ReadAllText("todecode.txt");
	button2->Enabled = true;
}

// Кнопка - декодировать текст
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	h->decode(todecode, decoded);
	richTextBox2->Text = File::ReadAllText("decoded.txt");
	richTextBox1->Text = File::ReadAllText("todecode.txt");
}

private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void richTextBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void richTextBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
