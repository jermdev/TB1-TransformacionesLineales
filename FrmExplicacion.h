#pragma once

namespace TB1TransformacionesLineales {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FrmExplicacion : public System::Windows::Forms::Form
	{
	public:
		FrmExplicacion(void)
		{
			InitializeComponent();
		}

	protected:
		~FrmExplicacion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnVolver; 

	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmExplicacion::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();

			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::LightGray;
			this->panel1->Controls->Add(this->btnVolver);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill; 
			this->panel1->AutoScroll = true; 
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->TabIndex = 0;

			// 
			// label2 
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(30, 118);
			this->label2->MaximumSize = System::Drawing::Size(900, 0); 
			this->label2->Name = L"label2";
			this->label2->TabIndex = 1;
			this->label2->Text = resources->GetString(L"label2.Text");

			// 
			// label1 
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Silver;
			this->label1->Font = (gcnew System::Drawing::Font(L"Agency FB", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(30, 20);
			this->label1->Name = L"label1";
			this->label1->TabIndex = 0;
			this->label1->Text = L"INSTRUCCIONES";

			// 
			// btnVolver 
			// 
			this->btnVolver->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnVolver->Location = System::Drawing::Point(800, 30); 
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(120, 50);
			this->btnVolver->TabIndex = 2;
			this->btnVolver->Text = L"Volver";
			this->btnVolver->UseVisualStyleBackColor = true;
			this->btnVolver->Click += gcnew System::EventHandler(this, &FrmExplicacion::btnVolver_Click);

			// 
			// FrmExplicacion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1000, 700); 
			this->Controls->Add(this->panel1);
			this->Name = L"FrmExplicacion";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen; 
			this->Text = L"Instrucciones de Uso";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		
	private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close(); 
	}
	};
}