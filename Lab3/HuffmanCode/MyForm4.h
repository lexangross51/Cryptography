#pragma once

namespace HuffmanCode {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm4
	/// </summary>
	public ref class MyForm4 : public System::Windows::Forms::Form
	{
	public:
		MyForm4(Hamming *_ham)
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
		~MyForm4()
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
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::RichTextBox^ richTextBox4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::RichTextBox^ richTextBox3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::RichTextBox^ richTextBox5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::RichTextBox^ richTextBox6;


		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox4 = (gcnew System::Windows::Forms::RichTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->richTextBox5 = (gcnew System::Windows::Forms::RichTextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->richTextBox6 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(145, 140);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(411, 96);
			this->richTextBox2->TabIndex = 24;
			this->richTextBox2->Text = L"";
			this->richTextBox2->TextChanged += gcnew System::EventHandler(this, &MyForm4::richTextBox2_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 140);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 34);
			this->label1->TabIndex = 23;
			this->label1->Text = L"Декодированный\r\nтекст\r\n";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(10, 66);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(129, 42);
			this->button2->TabIndex = 22;
			this->button2->Text = L"Декодировать \r\nтекст\r\n";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm4::button2_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(145, 12);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(411, 96);
			this->richTextBox1->TabIndex = 21;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm4::richTextBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(10, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(129, 31);
			this->button1->TabIndex = 20;
			this->button1->Text = L"Считать текст";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm4::button1_Click);
			// 
			// richTextBox4
			// 
			this->richTextBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox4->Location = System::Drawing::Point(815, 285);
			this->richTextBox4->Name = L"richTextBox4";
			this->richTextBox4->Size = System::Drawing::Size(168, 130);
			this->richTextBox4->TabIndex = 28;
			this->richTextBox4->Text = L"";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(812, 265);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(171, 17);
			this->label3->TabIndex = 27;
			this->label3->Text = L"Проверочная матрица H";
			// 
			// richTextBox3
			// 
			this->richTextBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox3->Location = System::Drawing::Point(623, 35);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(168, 214);
			this->richTextBox3->TabIndex = 26;
			this->richTextBox3->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(586, 12);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(205, 17);
			this->label2->TabIndex = 25;
			this->label2->Text = L"Алфавит и его кодовые слова";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 265);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(103, 17);
			this->label4->TabIndex = 29;
			this->label4->Text = L"Число ошибок";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(145, 265);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 30;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm4::textBox1_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(14, 295);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(119, 17);
			this->label5->TabIndex = 31;
			this->label5->Text = L"Позиции ошибок";
			// 
			// richTextBox5
			// 
			this->richTextBox5->Location = System::Drawing::Point(145, 295);
			this->richTextBox5->Name = L"richTextBox5";
			this->richTextBox5->Size = System::Drawing::Size(411, 103);
			this->richTextBox5->TabIndex = 32;
			this->richTextBox5->Text = L"";
			this->richTextBox5->TextChanged += gcnew System::EventHandler(this, &MyForm4::richTextBox5_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(855, 15);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(128, 17);
			this->label6->TabIndex = 34;
			this->label6->Text = L"Полученные коды";
			// 
			// richTextBox6
			// 
			this->richTextBox6->Location = System::Drawing::Point(808, 35);
			this->richTextBox6->Name = L"richTextBox6";
			this->richTextBox6->Size = System::Drawing::Size(175, 214);
			this->richTextBox6->TabIndex = 33;
			this->richTextBox6->Text = L"";
			this->richTextBox6->TextChanged += gcnew System::EventHandler(this, &MyForm4::richTextBox6_TextChanged);
			// 
			// MyForm4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(992, 434);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->richTextBox6);
			this->Controls->Add(this->richTextBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->richTextBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm4";
			this->Text = L"Декодировщик";
			this->Load += gcnew System::EventHandler(this, &MyForm4::MyForm4_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void MyForm4_Load(System::Object^ sender, System::EventArgs^ e)
{
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
	richTextBox1->ReadOnly = true;
	richTextBox2->ReadOnly = true;
	richTextBox3->ReadOnly = true;
	richTextBox4->ReadOnly = true;
	textBox1->ReadOnly = true;
	richTextBox5->ReadOnly = true;
	richTextBox6->ReadOnly = true;
	button2->Enabled = false;

	// Выводим матрицу
	std::ifstream matrix("matrixHam.txt");
	if (matrix.is_open())
	{
		std::string line, mat;
		getline(matrix, line);
		while (getline(matrix, line))
			mat += line + "\n";
		richTextBox4->Text = marshal_as<System::String^>(mat);
	}

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

	std::string codeHash = ham->getCodeHash();
	richTextBox6->Text = marshal_as<System::String^>(codeHash);
}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		richTextBox1->Text = File::ReadAllText("todecodeHam.txt");
		if (richTextBox1->Text != "")
			button2->Enabled = true;
		else
			MessageBox::Show("Файл с закодированным текстом пуст!");
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		std::string encoded_text;
		std::ifstream in("todecodeHam.txt");
		if (in.is_open())
		{
			std::string line;
			while (getline(in, line))
				encoded_text += line;				
		}

		std::string decoded = ham->decode();
		richTextBox2->Text = marshal_as<System::String^>(decoded);

		size_t err_count = ham->getErrCount();

		if (err_count) 
		{
			auto errs_pos = ham->getErrPos();

			std::string errs_pos_str;
			for (auto err : errs_pos)
				errs_pos_str += std::to_string(err) + ", ";
			errs_pos_str.resize(errs_pos_str.length() - 2);

			for (int i = errs_pos.size() - 1; i >= 0; i--) 
			{
				char err_bit = encoded_text[errs_pos[i] - 1];
				encoded_text = encoded_text.erase(errs_pos[i] - 1, 1);
				std::string insertBit = "(";
				insertBit += err_bit;
				insertBit += ")";
				encoded_text.insert(errs_pos[i] - 1, insertBit);
			}

			textBox1->Text = (String::Format("{0}", err_count));
			richTextBox5->Text = marshal_as<System::String^>(errs_pos_str);
			richTextBox1->Text = marshal_as<System::String^>(encoded_text);
		}
		else
		{
			textBox1->Text = (String::Format("{0}", 0));
			richTextBox5->Text = "Ошибок нет";
		}
	}

private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void richTextBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void richTextBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void richTextBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
