#pragma once
//JEREMI YA ENTRE

namespace TB1TransformacionesLineales {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmSimuladorTL
	/// </summary>
	public ref class FrmSimuladorTL : public System::Windows::Forms::Form
	{
	public:
		FrmSimuladorTL(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c?digo de constructor aqu?
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est?n usando.
		/// </summary>
		~FrmSimuladorTL()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Panel^ pnlMostrarFigura;
	private: System::Windows::Forms::GroupBox^ grpHomotecia;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::GroupBox^ grpFigura;
	private: System::Windows::Forms::Panel^ pnlFondo;
	private: System::Windows::Forms::RadioButton^ rbtnY;
	private: System::Windows::Forms::RadioButton^ rbtnX;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ lbFactor;
	private: System::Windows::Forms::TextBox^ txtFactor;
	private: System::Windows::Forms::Label^ lbAnguloRotacion;
	private: System::Windows::Forms::TextBox^ txtAnguloRotacion;
	private: System::Windows::Forms::Button^ btnRotar;
	private: System::Windows::Forms::Button^ btnDibujarFigura;
	private: System::Windows::Forms::TextBox^ txtCordenadasY;
	private: System::Windows::Forms::TextBox^ txtCordenadasX;
	private: System::Windows::Forms::Label^ lbCordenadasY;
	private: System::Windows::Forms::Label^ lbCordenadasX;
	private: System::Windows::Forms::ComboBox^ cboEjeReflexion;
	private: System::Windows::Forms::Button^ btnReflejar;


	private:
		/// <summary>
		/// Variable del dise?ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M?todo necesario para admitir el Dise?ador. No se puede modificar
		/// el contenido de este m?todo con el editor de c?digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pnlMostrarFigura = (gcnew System::Windows::Forms::Panel());
			this->grpHomotecia = (gcnew System::Windows::Forms::GroupBox());
			this->txtFactor = (gcnew System::Windows::Forms::TextBox());
			this->lbFactor = (gcnew System::Windows::Forms::Label());
			this->rbtnY = (gcnew System::Windows::Forms::RadioButton());
			this->rbtnX = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->cboEjeReflexion = (gcnew System::Windows::Forms::ComboBox());
			this->btnReflejar = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->btnRotar = (gcnew System::Windows::Forms::Button());
			this->lbAnguloRotacion = (gcnew System::Windows::Forms::Label());
			this->txtAnguloRotacion = (gcnew System::Windows::Forms::TextBox());
			this->grpFigura = (gcnew System::Windows::Forms::GroupBox());
			this->btnDibujarFigura = (gcnew System::Windows::Forms::Button());
			this->txtCordenadasY = (gcnew System::Windows::Forms::TextBox());
			this->txtCordenadasX = (gcnew System::Windows::Forms::TextBox());
			this->lbCordenadasY = (gcnew System::Windows::Forms::Label());
			this->lbCordenadasX = (gcnew System::Windows::Forms::Label());
			this->pnlFondo = (gcnew System::Windows::Forms::Panel());
			this->grpHomotecia->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->grpFigura->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlMostrarFigura
			// 
			this->pnlMostrarFigura->BackColor = System::Drawing::SystemColors::Window;
			this->pnlMostrarFigura->Location = System::Drawing::Point(285, 13);
			this->pnlMostrarFigura->Name = L"pnlMostrarFigura";
			this->pnlMostrarFigura->Size = System::Drawing::Size(746, 700);
			this->pnlMostrarFigura->TabIndex = 1;
			// 
			// grpHomotecia
			// 
			this->grpHomotecia->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->grpHomotecia->Controls->Add(this->txtFactor);
			this->grpHomotecia->Controls->Add(this->lbFactor);
			this->grpHomotecia->Controls->Add(this->rbtnY);
			this->grpHomotecia->Controls->Add(this->rbtnX);
			this->grpHomotecia->Controls->Add(this->radioButton1);
			this->grpHomotecia->Controls->Add(this->button1);
			this->grpHomotecia->Location = System::Drawing::Point(12, 547);
			this->grpHomotecia->Name = L"grpHomotecia";
			this->grpHomotecia->Size = System::Drawing::Size(253, 142);
			this->grpHomotecia->TabIndex = 0;
			this->grpHomotecia->TabStop = false;
			this->grpHomotecia->Text = L"Homotecia";
			// 
			// txtFactor
			// 
			this->txtFactor->Location = System::Drawing::Point(149, 37);
			this->txtFactor->Name = L"txtFactor";
			this->txtFactor->Size = System::Drawing::Size(84, 22);
			this->txtFactor->TabIndex = 6;
			// 
			// lbFactor
			// 
			this->lbFactor->AutoSize = true;
			this->lbFactor->Location = System::Drawing::Point(7, 40);
			this->lbFactor->Name = L"lbFactor";
			this->lbFactor->Size = System::Drawing::Size(48, 16);
			this->lbFactor->TabIndex = 5;
			this->lbFactor->Text = L"Factor:";
			// 
			// rbtnY
			// 
			this->rbtnY->AutoSize = true;
			this->rbtnY->Location = System::Drawing::Point(149, 79);
			this->rbtnY->Name = L"rbtnY";
			this->rbtnY->Size = System::Drawing::Size(37, 20);
			this->rbtnY->TabIndex = 3;
			this->rbtnY->TabStop = true;
			this->rbtnY->Text = L"Y";
			this->rbtnY->UseVisualStyleBackColor = true;
			// 
			// rbtnX
			// 
			this->rbtnX->AutoSize = true;
			this->rbtnX->Location = System::Drawing::Point(107, 79);
			this->rbtnX->Name = L"rbtnX";
			this->rbtnX->Size = System::Drawing::Size(36, 20);
			this->rbtnX->TabIndex = 2;
			this->rbtnX->TabStop = true;
			this->rbtnX->Text = L"X";
			this->rbtnX->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(6, 79);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(84, 20);
			this->radioButton1->TabIndex = 1;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Simetrico";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 105);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(241, 26);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Aplicar";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->groupBox2->Controls->Add(this->cboEjeReflexion);
			this->groupBox2->Controls->Add(this->btnReflejar);
			this->groupBox2->Location = System::Drawing::Point(12, 190);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(253, 142);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Reflexion";
			// 
			// cboEjeReflexion
			// 
			this->cboEjeReflexion->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboEjeReflexion->FormattingEnabled = true;
			this->cboEjeReflexion->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Eje X", L"Eje Y" });
			this->cboEjeReflexion->Location = System::Drawing::Point(10, 53);
			this->cboEjeReflexion->Name = L"cboEjeReflexion";
			this->cboEjeReflexion->Size = System::Drawing::Size(223, 24);
			this->cboEjeReflexion->TabIndex = 11;
			// 
			// btnReflejar
			// 
			this->btnReflejar->Location = System::Drawing::Point(6, 98);
			this->btnReflejar->Name = L"btnReflejar";
			this->btnReflejar->Size = System::Drawing::Size(241, 26);
			this->btnReflejar->TabIndex = 10;
			this->btnReflejar->Text = L"Reflejar";
			this->btnReflejar->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->groupBox3->Controls->Add(this->btnRotar);
			this->groupBox3->Controls->Add(this->lbAnguloRotacion);
			this->groupBox3->Controls->Add(this->txtAnguloRotacion);
			this->groupBox3->Location = System::Drawing::Point(12, 370);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(253, 142);
			this->groupBox3->TabIndex = 1;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Rotacion";
			// 
			// btnRotar
			// 
			this->btnRotar->Location = System::Drawing::Point(6, 100);
			this->btnRotar->Name = L"btnRotar";
			this->btnRotar->Size = System::Drawing::Size(241, 26);
			this->btnRotar->TabIndex = 9;
			this->btnRotar->Text = L"Rotar";
			this->btnRotar->UseVisualStyleBackColor = true;
			// 
			// lbAnguloRotacion
			// 
			this->lbAnguloRotacion->AutoSize = true;
			this->lbAnguloRotacion->Location = System::Drawing::Point(10, 60);
			this->lbAnguloRotacion->Name = L"lbAnguloRotacion";
			this->lbAnguloRotacion->Size = System::Drawing::Size(125, 16);
			this->lbAnguloRotacion->TabIndex = 8;
			this->lbAnguloRotacion->Text = L"Angulo de Rotacion";
			this->lbAnguloRotacion->Click += gcnew System::EventHandler(this, &FrmSimuladorTL::label1_Click);
			// 
			// txtAnguloRotacion
			// 
			this->txtAnguloRotacion->Location = System::Drawing::Point(149, 60);
			this->txtAnguloRotacion->Name = L"txtAnguloRotacion";
			this->txtAnguloRotacion->Size = System::Drawing::Size(84, 22);
			this->txtAnguloRotacion->TabIndex = 7;
			this->txtAnguloRotacion->TextChanged += gcnew System::EventHandler(this, &FrmSimuladorTL::textBox1_TextChanged);
			// 
			// grpFigura
			// 
			this->grpFigura->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->grpFigura->Controls->Add(this->btnDibujarFigura);
			this->grpFigura->Controls->Add(this->txtCordenadasY);
			this->grpFigura->Controls->Add(this->txtCordenadasX);
			this->grpFigura->Controls->Add(this->lbCordenadasY);
			this->grpFigura->Controls->Add(this->lbCordenadasX);
			this->grpFigura->Location = System::Drawing::Point(12, 13);
			this->grpFigura->Name = L"grpFigura";
			this->grpFigura->Size = System::Drawing::Size(253, 142);
			this->grpFigura->TabIndex = 1;
			this->grpFigura->TabStop = false;
			this->grpFigura->Text = L"Figura";
			// 
			// btnDibujarFigura
			// 
			this->btnDibujarFigura->Location = System::Drawing::Point(6, 110);
			this->btnDibujarFigura->Name = L"btnDibujarFigura";
			this->btnDibujarFigura->Size = System::Drawing::Size(241, 26);
			this->btnDibujarFigura->TabIndex = 13;
			this->btnDibujarFigura->Text = L"Dibujar Figura";
			this->btnDibujarFigura->UseVisualStyleBackColor = true;
			// 
			// txtCordenadasY
			// 
			this->txtCordenadasY->Location = System::Drawing::Point(113, 70);
			this->txtCordenadasY->Name = L"txtCordenadasY";
			this->txtCordenadasY->Size = System::Drawing::Size(121, 22);
			this->txtCordenadasY->TabIndex = 12;
			// 
			// txtCordenadasX
			// 
			this->txtCordenadasX->Location = System::Drawing::Point(112, 32);
			this->txtCordenadasX->Name = L"txtCordenadasX";
			this->txtCordenadasX->Size = System::Drawing::Size(121, 22);
			this->txtCordenadasX->TabIndex = 11;
			// 
			// lbCordenadasY
			// 
			this->lbCordenadasY->AutoSize = true;
			this->lbCordenadasY->Location = System::Drawing::Point(10, 70);
			this->lbCordenadasY->Name = L"lbCordenadasY";
			this->lbCordenadasY->Size = System::Drawing::Size(97, 16);
			this->lbCordenadasY->TabIndex = 10;
			this->lbCordenadasY->Text = L"Cordenadas Y:";
			// 
			// lbCordenadasX
			// 
			this->lbCordenadasX->AutoSize = true;
			this->lbCordenadasX->Location = System::Drawing::Point(3, 38);
			this->lbCordenadasX->Name = L"lbCordenadasX";
			this->lbCordenadasX->Size = System::Drawing::Size(96, 16);
			this->lbCordenadasX->TabIndex = 9;
			this->lbCordenadasX->Text = L"Cordenadas X:";
			// 
			// pnlFondo
			// 
			this->pnlFondo->BackColor = System::Drawing::SystemColors::Window;
			this->pnlFondo->Location = System::Drawing::Point(285, 13);
			this->pnlFondo->Name = L"pnlFondo";
			this->pnlFondo->Size = System::Drawing::Size(746, 700);
			this->pnlFondo->TabIndex = 2;
			// 
			// FrmSimuladorTL
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1043, 734);
			this->Controls->Add(this->grpHomotecia);
			this->Controls->Add(this->grpFigura);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->pnlMostrarFigura);
			this->Controls->Add(this->pnlFondo);
			this->Name = L"FrmSimuladorTL";
			this->Text = L"FrmSimuladorTL";
			this->grpHomotecia->ResumeLayout(false);
			this->grpHomotecia->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->grpFigura->ResumeLayout(false);
			this->grpFigura->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion



private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
