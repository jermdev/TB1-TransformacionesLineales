#pragma once
#include "FrmSimuladorTL.h"
#include "FrmExplicacion.h"

namespace TB1TransformacionesLineales {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FrmPrincipal : public System::Windows::Forms::Form
	{
	public:
		FrmPrincipal(void)
		{
			InitializeComponent();
		}

	protected:
		~FrmPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ labelTitulo;
	private: System::Windows::Forms::Button^ btnIniciar;
	private: System::Windows::Forms::Button^ btnExplicacion;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnExplicacion = (gcnew System::Windows::Forms::Button());
			this->btnIniciar = (gcnew System::Windows::Forms::Button());
			this->labelTitulo = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel1->Controls->Add(this->btnExplicacion);
			this->panel1->Controls->Add(this->btnIniciar);
			this->panel1->Controls->Add(this->labelTitulo);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(882, 553);
			this->panel1->TabIndex = 0;
			// 
			// btnExplicacion
			// 
			this->btnExplicacion->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnExplicacion->BackColor = System::Drawing::Color::White;
			this->btnExplicacion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnExplicacion->Location = System::Drawing::Point(290, 360);
			this->btnExplicacion->Name = L"btnExplicacion";
			this->btnExplicacion->Size = System::Drawing::Size(300, 80);
			this->btnExplicacion->TabIndex = 2;
			this->btnExplicacion->Text = L"Ver Funcionamiento";
			this->btnExplicacion->UseVisualStyleBackColor = false;
			this->btnExplicacion->Click += gcnew System::EventHandler(this, &FrmPrincipal::btnExplicacion_Click);
			// 
			// btnIniciar
			// 
			this->btnIniciar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnIniciar->BackColor = System::Drawing::Color::White;
			this->btnIniciar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnIniciar->Location = System::Drawing::Point(290, 250);
			this->btnIniciar->Name = L"btnIniciar";
			this->btnIniciar->Size = System::Drawing::Size(300, 80);
			this->btnIniciar->TabIndex = 1;
			this->btnIniciar->Text = L"Iniciar Programa";
			this->btnIniciar->UseVisualStyleBackColor = false;
			this->btnIniciar->Click += gcnew System::EventHandler(this, &FrmPrincipal::btnIniciar_Click);
			// 
			// labelTitulo
			// 
			this->labelTitulo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelTitulo->BackColor = System::Drawing::Color::Transparent;
			this->labelTitulo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitulo->Location = System::Drawing::Point(0, 70);
			this->labelTitulo->Name = L"labelTitulo";
			this->labelTitulo->Size = System::Drawing::Size(882, 140);
			this->labelTitulo->TabIndex = 0;
			this->labelTitulo->Text = L"TRANSFORMACIONES\nLINEALES";
			this->labelTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// FrmPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(882, 553);
			this->Controls->Add(this->panel1);
			this->Name = L"FrmPrincipal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menú Principal";
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnIniciar_Click(System::Object^ sender, System::EventArgs^ e) {
		FrmSimuladorTL^ frmSimulador = gcnew FrmSimuladorTL();
		this->Hide();
		frmSimulador->ShowDialog();
		this->Show();
	}
	private: System::Void btnExplicacion_Click(System::Object^ sender, System::EventArgs^ e) {
		FrmExplicacion^ frmExplicacion = gcnew FrmExplicacion();
		this->Hide();
		frmExplicacion->ShowDialog();
		this->Show();
	}
	};
}