#pragma once
#include <iostream>
#include <string>
#include <msclr\marshal_cppstd.h>

#include "stack.h"
namespace VisPart {
	using namespace std;
	using namespace msclr::interop;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
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
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxUsInp;
	protected:

	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ AnswerLabel;
	private: System::Windows::Forms::Label^ label2;

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBoxUsInp = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->AnswerLabel = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBoxUsInp
			// 
			this->textBoxUsInp->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxUsInp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxUsInp->ForeColor = System::Drawing::SystemColors::WindowText;
			this->textBoxUsInp->Location = System::Drawing::Point(56, 125);
			this->textBoxUsInp->Name = L"textBoxUsInp";
			this->textBoxUsInp->Size = System::Drawing::Size(482, 44);
			this->textBoxUsInp->TabIndex = 0;
			this->textBoxUsInp->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxUsImp_TextChanged);
			// 
			// button1
			// 
			this->button1->FlatAppearance->BorderSize = 5;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(798, 95);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(183, 111);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Ќј∆ћ»";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(568, 132);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 37);
			this->label1->TabIndex = 2;
			this->label1->Text = L"=";
			// 
			// AnswerLabel
			// 
			this->AnswerLabel->AutoSize = true;
			this->AnswerLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AnswerLabel->Location = System::Drawing::Point(631, 132);
			this->AnswerLabel->Name = L"AnswerLabel";
			this->AnswerLabel->Size = System::Drawing::Size(35, 37);
			this->AnswerLabel->TabIndex = 3;
			this->AnswerLabel->Text = L"0";
			this->AnswerLabel->Click += gcnew System::EventHandler(this, &MyForm::AnswerLabel_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(62, 241);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"label2";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1068, 311);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->AnswerLabel);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBoxUsInp);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBoxUsImp_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		button1_Click(sender, e);
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		string a = msclr::interop::marshal_as<std::string>(textBoxUsInp->Text);
		if (a.size() ==0 ) return;
		TCalculator Tcalc;
		try {
			Tcalc.SetExpression(a);
			Tcalc.ToPostfix();
			label2->Text = msclr::interop::marshal_as<String^>(Tcalc.GetPostfix());
			//AnswerLabel->Text = msclr::interop::marshal_as<String^>(Tcalc.CalcPostfix());
			//AnswerLabel->Text = Convert::ToString(Tcalc.GetExpression().ToString());
			AnswerLabel->Text = Convert::ToString(Tcalc.CalcPostfix());
		}
		catch (...) { AnswerLabel->Text = Convert::ToString("ERROR"); }
	}
	private: System::Void AnswerLabel_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
