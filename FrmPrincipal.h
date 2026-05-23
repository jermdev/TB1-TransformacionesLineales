#pragma once
#include"FrmSimuladorTL.h"
#include"FrmExplicacion.h"

namespace TB1TransformacionesLineales {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmPrincipal
	/// </summary>
	public ref class FrmPrincipal : public System::Windows::Forms::Form
	{
	public:
		FrmPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
	

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FrmPrincipal()
		{
			if (components)
			{
				delete components;
			}
		
		}
	private: System::Windows::Forms::Button^ btnIniciarPrograma;
	private: System::Windows::Forms::Button^ btnVerFuncionamiento;
	protected:
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;

	protected:


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnIniciarPrograma = (gcnew System::Windows::Forms::Button());
			this->btnVerFuncionamiento = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnIniciarPrograma
			// 
			this->btnIniciarPrograma->Font = (gcnew System::Drawing::Font(L"Elephant", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnIniciarPrograma->Location = System::Drawing::Point(223, 349);
			this->btnIniciarPrograma->Name = L"btnIniciarPrograma";
			this->btnIniciarPrograma->Size = System::Drawing::Size(407, 126);
			this->btnIniciarPrograma->TabIndex = 0;
			this->btnIniciarPrograma->Text = L"Iniciar Programa";
			this->btnIniciarPrograma->UseVisualStyleBackColor = true;
			this->btnIniciarPrograma->Click += gcnew System::EventHandler(this, &FrmPrincipal::btnIniciarPrograma_Click);
			// 
			// btnVerFuncionamiento
			// 
			this->btnVerFuncionamiento->Font = (gcnew System::Drawing::Font(L"Elephant", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnVerFuncionamiento->Location = System::Drawing::Point(223, 538);
			this->btnVerFuncionamiento->Name = L"btnVerFuncionamiento";
			this->btnVerFuncionamiento->Size = System::Drawing::Size(407, 126);
			this->btnVerFuncionamiento->TabIndex = 1;
			this->btnVerFuncionamiento->Text = L"Ver Funcionamiento";
			this->btnVerFuncionamiento->UseVisualStyleBackColor = true;
			this->btnVerFuncionamiento->Click += gcnew System::EventHandler(this, &FrmPrincipal::btnVerFuncionamiento_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->btnVerFuncionamiento);
			this->panel1->Controls->Add(this->btnIniciarPrograma);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Location = System::Drawing::Point(0, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(995, 736);
			this->panel1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::Control;
			this->label1->Font = (gcnew System::Drawing::Font(L"Agency FB", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(145, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(548, 192);
			this->label1->TabIndex = 2;
			this->label1->Text = L"TRANSFORMACIONES\r\n          LINEALES\r\n";
			// 
			// panel2
			// 
			this->panel2->Location = System::Drawing::Point(142, 62);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(532, 181);
			this->panel2->TabIndex = 3;
			// 
			// FrmPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(836, 716);
			this->Controls->Add(this->panel1);
			this->Name = L"FrmPrincipal";
			this->Text = L"FrmPrincipal";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	
private: System::Void btnIniciarPrograma_Click(System::Object^ sender, System::EventArgs^ e) {
	
	FrmSimuladorTL^ frmSimulador= gcnew FrmSimuladorTL();
	this->Hide();
	frmSimulador->ShowDialog();
	this->Show();

}
private: System::Void btnVerFuncionamiento_Click(System::Object^ sender, System::EventArgs^ e) {
	
	FrmExplicacion^ frmExplicacion = gcnew FrmExplicacion();
	this->Hide();
	frmExplicacion->ShowDialog();
	this->Show();

}
};
}
