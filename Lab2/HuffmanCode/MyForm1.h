#pragma once
#include "Huffman.h"

namespace HuffmanCode 
{
	const std::string alph = "alph.txt";
	const std::string prob_p1 = "prob_p1.txt";
	const std::string prob_p2 = "prob_p2.txt";
	const std::string codes = "codes.txt";
	const std::string toencode = "toencode.txt";
	const std::string todecode = "todecode.txt";
	const std::string decoded = "decoded.txt";

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Сводка для MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(Huffman *_h)
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
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ Избыточность;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::RichTextBox^ richTextBox3;
	private: System::Windows::Forms::Label^ label5;



	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		/// 
		Huffman* h;
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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Избыточность = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(121, 28);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Считать текст";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(146, 12);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(432, 98);
			this->richTextBox1->TabIndex = 2;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm1::richTextBox1_TextChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 64);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(121, 46);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Закодировать текст\r\n";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(146, 161);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(432, 98);
			this->richTextBox2->TabIndex = 4;
			this->richTextBox2->Text = L"";
			this->richTextBox2->TextChanged += gcnew System::EventHandler(this, &MyForm1::richTextBox2_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 161);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(121, 34);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Закодированный\r\nтекст\r\n";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 291);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(109, 34);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Средняя длина\r\nкодового слова";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(127, 291);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(149, 22);
			this->textBox1->TabIndex = 7;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBox1_TextChanged);
			// 
			// Избыточность
			// 
			this->Избыточность->AutoSize = true;
			this->Избыточность->Location = System::Drawing::Point(12, 340);
			this->Избыточность->Name = L"Избыточность";
			this->Избыточность->Size = System::Drawing::Size(103, 17);
			this->Избыточность->TabIndex = 8;
			this->Избыточность->Text = L"Избыточность";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(127, 340);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(149, 22);
			this->textBox2->TabIndex = 9;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBox2_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 385);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(94, 34);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Неравенство\r\nКрафта";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(127, 385);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(149, 22);
			this->textBox3->TabIndex = 11;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBox3_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(637, 12);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(181, 17);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Выберите распределение";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(698, 32);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 68);
			this->listBox1->TabIndex = 13;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm1::listBox1_SelectedIndexChanged);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(698, 130);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(120, 49);
			this->button3->TabIndex = 14;
			this->button3->Text = L"Закодировать алфавит";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm1::button3_Click);
			// 
			// richTextBox3
			// 
			this->richTextBox3->Location = System::Drawing::Point(640, 247);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(178, 172);
			this->richTextBox3->TabIndex = 15;
			this->richTextBox3->Text = L"";
			this->richTextBox3->TextChanged += gcnew System::EventHandler(this, &MyForm1::richTextBox3_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(698, 210);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(120, 34);
			this->label5->TabIndex = 16;
			this->label5->Text = L"Кодовые слова \r\nкаждого символа\r\n";
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(839, 433);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->Избыточность);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm1";
			this->Text = L"Кодировщик";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	// Вывод информации (средняя длина, избыточность, нер-во Крафта)
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

	// Включить\выключить элементы управления
	void OnOffElements(bool isActive)
	{
		button2->Enabled = isActive;
		richTextBox2->Enabled = isActive;
		textBox1->Enabled = isActive;
		textBox2->Enabled = isActive;
		textBox3->Enabled = isActive;
		listBox1->Enabled = isActive;
		button3->Enabled = isActive;
		richTextBox3->Enabled = isActive;
	}

	// Действия при загрузке формы
	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
		richTextBox1->ReadOnly = true;
		richTextBox2->ReadOnly = true;
		richTextBox3->ReadOnly = true;
		textBox1->ReadOnly = true;
		textBox2->ReadOnly = true;
		textBox3->ReadOnly = true;


		listBox1->Items->Add("Равномерное");
		listBox1->Items->Add("P1");
		listBox1->Items->Add("P2");
		OnOffElements(false);
	}

	// Кнопка - считать текст
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		h->readText(toencode);
		if (!h->isEmptyText())
		{
			richTextBox1->Text = File::ReadAllText("toencode.txt");
			OnOffElements(true);
			button2->Enabled = false;
		}
		else
			MessageBox::Show("Файл с текстом пуст!");
	}
	
	// Кнопка - закодировать текст
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// Если кодовая таблица пустая, значит алфавит еще не зашифрован, поэтому 
		// символы текста имеют равномерное распределение
		if (h->isEmptyTable())
		{
			h->clearTable();
			h->encode(todecode, codes);
			richTextBox3->Text = File::ReadAllText("codes.txt");
			writeInfo();
		}
		// Иначе кодируем на основе уже созданной таблицы
		else
		{
			h->encode_by_table(todecode);
		}
		richTextBox2->Text = File::ReadAllText("todecode.txt");
	}

	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) 
	{
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void richTextBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

// Кнопка - закодировать алфавит
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
{
	// Определяем какое распределение выбрано
	size_t distr = listBox1->SelectedIndex;

	switch (distr)
	{
	case 0: {
		h->clearTable();
		richTextBox3->Text = "Последовательность\nподчинаяется\nравномерному\nраспределению. " +
			"Чтобы увидеть\nздесь коды, нужно \nзакодировать\nтекст";
		button2->Enabled = true;
		break;
	}

	case 1: {
		richTextBox3->Clear();
		h->clearTable();
		h->encodeAlphabet(alph, prob_p1, codes);
		richTextBox3->Text = File::ReadAllText("codes.txt");
		writeInfo();
		button2->Enabled = true;
		break;
	}

	case 2: {
		richTextBox3->Clear();
		h->clearTable();
		h->encodeAlphabet(alph, prob_p2, codes);
		richTextBox3->Text = File::ReadAllText("codes.txt");
		writeInfo();
		button2->Enabled = true;
		break;
	}
	default: {
		MessageBox::Show("Не выбрано распределение!");
		break;
	}
	}

}
private: System::Void richTextBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
