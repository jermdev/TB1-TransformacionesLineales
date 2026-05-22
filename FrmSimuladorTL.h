#pragma once

#include "Figura.h"
#include "Dibujador.h"
#include "Reflexion.h"
#include "Trasformacion.h"
#include "Rotacion.h"
#include "Animacion.h"
#include "Homotecia.h"

class TransRestablecer : public Trasformacion {
private:
	Figura* estadoAnterior;
public:
	TransRestablecer(Figura* actual, Figura* anterior) : Trasformacion(actual) {
		this->estadoAnterior = anterior;
	}
	void trasformacion() override {
		auto ptsAct = getFigura()->getPuntos();
		auto ptsAnt = estadoAnterior->getPuntos();
		if (ptsAct.size() == ptsAnt.size()) {
			for (size_t i = 0; i < ptsAct.size(); i++) {
				ptsAct[i]->setX(ptsAnt[i]->getX());
				ptsAct[i]->setY(ptsAnt[i]->getY());
			}
		}
	}
};

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
			dibujador = new Dibujador();
			escalaGrid = 30.0;
			cachedEscalaGrid = 0.0;
			mostrarRecta = false;
			esHomotecia = false;
			reflecM = 0.0;
			reflecB = 0.0;

			int x = pnlDibujar->Width;
			int y = pnlDibujar->Height;

			figuraAnterior = new Figura(x / 2, y / 2);
			figuraActual = new Figura(x / 2, y / 2);
			figuraBaseOriginal = nullptr;

			timer1->Interval = 50;
			animacion = nullptr;

			this->SetStyle(System::Windows::Forms::ControlStyles::UserPaint |
				System::Windows::Forms::ControlStyles::AllPaintingInWmPaint |
				System::Windows::Forms::ControlStyles::OptimizedDoubleBuffer, true);
			this->UpdateStyles();

			this->pnlDibujar->GetType()->GetMethod("SetStyle", System::Reflection::BindingFlags::NonPublic | System::Reflection::BindingFlags::Instance)
				->Invoke(this->pnlDibujar, gcnew cli::array<System::Object^>{
				System::Windows::Forms::ControlStyles::AllPaintingInWmPaint |
					System::Windows::Forms::ControlStyles::UserPaint |
					System::Windows::Forms::ControlStyles::OptimizedDoubleBuffer, true
			});
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
			if (cachedPnlDibujar) { delete cachedPnlDibujar; cachedPnlDibujar = nullptr; }
			if (figuraAnterior) { delete figuraAnterior; figuraAnterior = nullptr; }
			if (figuraActual) { delete figuraActual; figuraActual = nullptr; }
			if (figuraBaseOriginal) { delete figuraBaseOriginal; figuraBaseOriginal = nullptr; }
			if (dibujador) { delete dibujador; dibujador = nullptr; }
		}

	private: System::Windows::Forms::GroupBox^ grpHomotecia;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::GroupBox^ grpFigura;
	private: System::Windows::Forms::Panel^ pnlDibujar;
	private: System::Windows::Forms::RadioButton^ rbtnY;
	private: System::Windows::Forms::RadioButton^ rbtnX;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::Button^ btnHomotencia;
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
	private: System::ComponentModel::IContainer^ components;

	private:
		Bitmap^ cachedPnlDibujar;
		Figura* figuraAnterior;
		Figura* figuraActual;
		Figura* figuraBaseOriginal;
		Trasformacion* trasformacion;
		Dibujador* dibujador;
		double reflecM;
		double reflecB;
		bool mostrarRecta;
		bool esHomotecia;
		double escalaGrid;
		double cachedEscalaGrid;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ btnRestablecerFigura;
	private: System::Windows::Forms::Button^ btnReiniciar;
	private: System::Windows::Forms::TextBox^ txtPendiente;
	private: System::Windows::Forms::Label^ lbEcuacionRecta;
	private: System::Windows::Forms::Label^ lbPendiente;
	private: System::Windows::Forms::Label^ lbCordenadaOrigen;
	private: System::Windows::Forms::TextBox^ txtCordenadaOrigen;
	private: System::Windows::Forms::Button^ btnTriangulo;
	private: System::Windows::Forms::Button^ btnCuadrado;
		   Animacion* animacion;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// M?todo necesario para admitir el Dise?ador. No se puede modificar
		   /// el contenido de este m?todo con el editor de c?digo.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->grpHomotecia = (gcnew System::Windows::Forms::GroupBox());
			   this->txtFactor = (gcnew System::Windows::Forms::TextBox());
			   this->lbFactor = (gcnew System::Windows::Forms::Label());
			   this->rbtnY = (gcnew System::Windows::Forms::RadioButton());
			   this->rbtnX = (gcnew System::Windows::Forms::RadioButton());
			   this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			   this->btnHomotencia = (gcnew System::Windows::Forms::Button());
			   this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			   this->txtCordenadaOrigen = (gcnew System::Windows::Forms::TextBox());
			   this->lbCordenadaOrigen = (gcnew System::Windows::Forms::Label());
			   this->lbPendiente = (gcnew System::Windows::Forms::Label());
			   this->lbEcuacionRecta = (gcnew System::Windows::Forms::Label());
			   this->txtPendiente = (gcnew System::Windows::Forms::TextBox());
			   this->cboEjeReflexion = (gcnew System::Windows::Forms::ComboBox());
			   this->btnReflejar = (gcnew System::Windows::Forms::Button());
			   this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			   this->btnRotar = (gcnew System::Windows::Forms::Button());
			   this->lbAnguloRotacion = (gcnew System::Windows::Forms::Label());
			   this->txtAnguloRotacion = (gcnew System::Windows::Forms::TextBox());
			   this->grpFigura = (gcnew System::Windows::Forms::GroupBox());
			   this->btnDibujarFigura = (gcnew System::Windows::Forms::Button());
			   this->btnTriangulo = (gcnew System::Windows::Forms::Button());
			   this->btnCuadrado = (gcnew System::Windows::Forms::Button());
			   this->txtCordenadasY = (gcnew System::Windows::Forms::TextBox());
			   this->txtCordenadasX = (gcnew System::Windows::Forms::TextBox());
			   this->lbCordenadasY = (gcnew System::Windows::Forms::Label());
			   this->lbCordenadasX = (gcnew System::Windows::Forms::Label());
			   this->pnlDibujar = (gcnew System::Windows::Forms::Panel());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->btnRestablecerFigura = (gcnew System::Windows::Forms::Button());
			   this->btnReiniciar = (gcnew System::Windows::Forms::Button());
			   this->grpHomotecia->SuspendLayout();
			   this->groupBox2->SuspendLayout();
			   this->groupBox3->SuspendLayout();
			   this->grpFigura->SuspendLayout();
			   this->SuspendLayout();

			   this->grpHomotecia->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			   this->grpHomotecia->Controls->Add(this->txtFactor);
			   this->grpHomotecia->Controls->Add(this->lbFactor);
			   this->grpHomotecia->Controls->Add(this->rbtnY);
			   this->grpHomotecia->Controls->Add(this->rbtnX);
			   this->grpHomotecia->Controls->Add(this->radioButton1);
			   this->grpHomotecia->Controls->Add(this->btnHomotencia);
			   this->grpHomotecia->Location = System::Drawing::Point(18, 515);
			   this->grpHomotecia->Name = L"grpHomotecia";
			   this->grpHomotecia->Size = System::Drawing::Size(253, 142);
			   this->grpHomotecia->TabIndex = 0;
			   this->grpHomotecia->TabStop = false;
			   this->grpHomotecia->Text = L"Homotecia";

			   this->txtFactor->Location = System::Drawing::Point(149, 37);
			   this->txtFactor->Name = L"txtFactor";
			   this->txtFactor->Size = System::Drawing::Size(84, 22);
			   this->txtFactor->TabIndex = 6;

			   this->lbFactor->AutoSize = true;
			   this->lbFactor->Location = System::Drawing::Point(7, 40);
			   this->lbFactor->Name = L"lbFactor";
			   this->lbFactor->Size = System::Drawing::Size(48, 16);
			   this->lbFactor->TabIndex = 5;
			   this->lbFactor->Text = L"Factor:";

			   this->rbtnY->AutoSize = true;
			   this->rbtnY->Location = System::Drawing::Point(149, 79);
			   this->rbtnY->Name = L"rbtnY";
			   this->rbtnY->Size = System::Drawing::Size(37, 20);
			   this->rbtnY->TabIndex = 3;
			   this->rbtnY->TabStop = true;
			   this->rbtnY->Text = L"Y";
			   this->rbtnY->UseVisualStyleBackColor = true;

			   this->rbtnX->AutoSize = true;
			   this->rbtnX->Location = System::Drawing::Point(107, 79);
			   this->rbtnX->Name = L"rbtnX";
			   this->rbtnX->Size = System::Drawing::Size(36, 20);
			   this->rbtnX->TabIndex = 2;
			   this->rbtnX->TabStop = true;
			   this->rbtnX->Text = L"X";
			   this->rbtnX->UseVisualStyleBackColor = true;

			   this->radioButton1->AutoSize = true;
			   this->radioButton1->Location = System::Drawing::Point(6, 79);
			   this->radioButton1->Name = L"radioButton1";
			   this->radioButton1->Size = System::Drawing::Size(84, 20);
			   this->radioButton1->TabIndex = 1;
			   this->radioButton1->TabStop = true;
			   this->radioButton1->Text = L"Simetrico";
			   this->radioButton1->UseVisualStyleBackColor = true;

			   this->btnHomotencia->Location = System::Drawing::Point(6, 105);
			   this->btnHomotencia->Name = L"btnHomotencia";
			   this->btnHomotencia->Size = System::Drawing::Size(241, 26);
			   this->btnHomotencia->TabIndex = 0;
			   this->btnHomotencia->Text = L"Aplicar";
			   this->btnHomotencia->UseVisualStyleBackColor = true;
			   this->btnHomotencia->Click += gcnew System::EventHandler(this, &FrmSimuladorTL::btnHomotencia_Click);

			   this->groupBox2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			   this->groupBox2->Controls->Add(this->txtCordenadaOrigen);
			   this->groupBox2->Controls->Add(this->lbCordenadaOrigen);
			   this->groupBox2->Controls->Add(this->lbPendiente);
			   this->groupBox2->Controls->Add(this->lbEcuacionRecta);
			   this->groupBox2->Controls->Add(this->txtPendiente);
			   this->groupBox2->Controls->Add(this->cboEjeReflexion);
			   this->groupBox2->Controls->Add(this->btnReflejar);
			   this->groupBox2->Location = System::Drawing::Point(12, 195);
			   this->groupBox2->Name = L"groupBox2";
			   this->groupBox2->Size = System::Drawing::Size(253, 161);
			   this->groupBox2->TabIndex = 1;
			   this->groupBox2->TabStop = false;
			   this->groupBox2->Text = L"Reflexion";

			   this->txtCordenadaOrigen->Location = System::Drawing::Point(141, 94);
			   this->txtCordenadaOrigen->Name = L"txtCordenadaOrigen";
			   this->txtCordenadaOrigen->Size = System::Drawing::Size(56, 22);
			   this->txtCordenadaOrigen->TabIndex = 16;
			   this->txtCordenadaOrigen->Visible = false;

			   this->lbCordenadaOrigen->AutoSize = true;
			   this->lbCordenadaOrigen->Location = System::Drawing::Point(114, 97);
			   this->lbCordenadaOrigen->Name = L"lbCordenadaOrigen";
			   this->lbCordenadaOrigen->Size = System::Drawing::Size(18, 16);
			   this->lbCordenadaOrigen->TabIndex = 15;
			   this->lbCordenadaOrigen->Text = L"b:";
			   this->lbCordenadaOrigen->Visible = false;

			   this->lbPendiente->AutoSize = true;
			   this->lbPendiente->Location = System::Drawing::Point(13, 97);
			   this->lbPendiente->Name = L"lbPendiente";
			   this->lbPendiente->Size = System::Drawing::Size(21, 16);
			   this->lbPendiente->TabIndex = 14;
			   this->lbPendiente->Text = L"m:";
			   this->lbPendiente->Visible = false;

			   this->lbEcuacionRecta->AutoSize = true;
			   this->lbEcuacionRecta->Location = System::Drawing::Point(10, 60);
			   this->lbEcuacionRecta->Name = L"lbEcuacionRecta";
			   this->lbEcuacionRecta->Size = System::Drawing::Size(167, 16);
			   this->lbEcuacionRecta->TabIndex = 13;
			   this->lbEcuacionRecta->Text = L"Ecuacion lineal (y = mx + b)";
			   this->lbEcuacionRecta->Visible = false;

			   this->txtPendiente->Location = System::Drawing::Point(40, 94);
			   this->txtPendiente->Name = L"txtPendiente";
			   this->txtPendiente->Size = System::Drawing::Size(56, 22);
			   this->txtPendiente->TabIndex = 12;
			   this->txtPendiente->Visible = false;

			   this->cboEjeReflexion->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->cboEjeReflexion->FormattingEnabled = true;
			   this->cboEjeReflexion->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Eje X", L"Eje Y", L"Recta general" });
			   this->cboEjeReflexion->Location = System::Drawing::Point(10, 21);
			   this->cboEjeReflexion->Name = L"cboEjeReflexion";
			   this->cboEjeReflexion->Size = System::Drawing::Size(223, 24);
			   this->cboEjeReflexion->TabIndex = 11;
			   this->cboEjeReflexion->SelectedIndexChanged += gcnew System::EventHandler(this, &FrmSimuladorTL::cboEjeReflexion_SelectedIndexChanged);

			   this->btnReflejar->Location = System::Drawing::Point(6, 122);
			   this->btnReflejar->Name = L"btnReflejar";
			   this->btnReflejar->Size = System::Drawing::Size(241, 26);
			   this->btnReflejar->TabIndex = 10;
			   this->btnReflejar->Text = L"Reflejar";
			   this->btnReflejar->UseVisualStyleBackColor = true;
			   this->btnReflejar->Click += gcnew System::EventHandler(this, &FrmSimuladorTL::btnReflejar_Click);

			   this->groupBox3->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			   this->groupBox3->Controls->Add(this->btnRotar);
			   this->groupBox3->Controls->Add(this->lbAnguloRotacion);
			   this->groupBox3->Controls->Add(this->txtAnguloRotacion);
			   this->groupBox3->Location = System::Drawing::Point(12, 365);
			   this->groupBox3->Name = L"groupBox3";
			   this->groupBox3->Size = System::Drawing::Size(253, 140);
			   this->groupBox3->TabIndex = 1;
			   this->groupBox3->TabStop = false;
			   this->groupBox3->Text = L"Rotacion";

			   this->btnRotar->Location = System::Drawing::Point(6, 100);
			   this->btnRotar->Name = L"btnRotar";
			   this->btnRotar->Size = System::Drawing::Size(241, 26);
			   this->btnRotar->TabIndex = 9;
			   this->btnRotar->Text = L"Rotar";
			   this->btnRotar->UseVisualStyleBackColor = true;
			   this->btnRotar->Click += gcnew System::EventHandler(this, &FrmSimuladorTL::btnRotar_Click);

			   this->lbAnguloRotacion->AutoSize = true;
			   this->lbAnguloRotacion->Location = System::Drawing::Point(10, 60);
			   this->lbAnguloRotacion->Name = L"lbAnguloRotacion";
			   this->lbAnguloRotacion->Size = System::Drawing::Size(125, 16);
			   this->lbAnguloRotacion->TabIndex = 8;
			   this->lbAnguloRotacion->Text = L"Angulo de Rotacion";

			   this->txtAnguloRotacion->Location = System::Drawing::Point(149, 60);
			   this->txtAnguloRotacion->Name = L"txtAnguloRotacion";
			   this->txtAnguloRotacion->Size = System::Drawing::Size(84, 22);
			   this->txtAnguloRotacion->TabIndex = 7;

			   this->grpFigura->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			   this->grpFigura->Controls->Add(this->btnDibujarFigura);
			   this->grpFigura->Controls->Add(this->btnTriangulo);
			   this->grpFigura->Controls->Add(this->btnCuadrado);
			   this->grpFigura->Controls->Add(this->txtCordenadasY);
			   this->grpFigura->Controls->Add(this->txtCordenadasX);
			   this->grpFigura->Controls->Add(this->lbCordenadasY);
			   this->grpFigura->Controls->Add(this->lbCordenadasX);
			   this->grpFigura->Location = System::Drawing::Point(12, 13);
			   this->grpFigura->Name = L"grpFigura";
			   this->grpFigura->Size = System::Drawing::Size(253, 175);
			   this->grpFigura->TabIndex = 1;
			   this->grpFigura->TabStop = false;
			   this->grpFigura->Text = L"Figura";

			   this->btnDibujarFigura->Location = System::Drawing::Point(6, 110);
			   this->btnDibujarFigura->Name = L"btnDibujarFigura";
			   this->btnDibujarFigura->Size = System::Drawing::Size(241, 26);
			   this->btnDibujarFigura->TabIndex = 13;
			   this->btnDibujarFigura->Text = L"Dibujar Figura";
			   this->btnDibujarFigura->UseVisualStyleBackColor = true;
			   this->btnDibujarFigura->Click += gcnew System::EventHandler(this, &FrmSimuladorTL::btnDibujarFigura_Click);

			   this->btnTriangulo->Location = System::Drawing::Point(6, 140);
			   this->btnTriangulo->Name = L"btnTriangulo";
			   this->btnTriangulo->Size = System::Drawing::Size(115, 26);
			   this->btnTriangulo->Text = L"Triangulo";
			   this->btnTriangulo->UseVisualStyleBackColor = true;
			   this->btnTriangulo->Click += gcnew System::EventHandler(this, &FrmSimuladorTL::btnTriangulo_Click);

			   this->btnCuadrado->Location = System::Drawing::Point(132, 140);
			   this->btnCuadrado->Name = L"btnCuadrado";
			   this->btnCuadrado->Size = System::Drawing::Size(115, 26);
			   this->btnCuadrado->Text = L"Cuadrado";
			   this->btnCuadrado->UseVisualStyleBackColor = true;
			   this->btnCuadrado->Click += gcnew System::EventHandler(this, &FrmSimuladorTL::btnCuadrado_Click);

			   this->txtCordenadasY->Location = System::Drawing::Point(113, 70);
			   this->txtCordenadasY->Name = L"txtCordenadasY";
			   this->txtCordenadasY->Size = System::Drawing::Size(121, 22);
			   this->txtCordenadasY->TabIndex = 12;

			   this->txtCordenadasX->Location = System::Drawing::Point(112, 32);
			   this->txtCordenadasX->Name = L"txtCordenadasX";
			   this->txtCordenadasX->Size = System::Drawing::Size(121, 22);
			   this->txtCordenadasX->TabIndex = 11;

			   this->lbCordenadasY->AutoSize = true;
			   this->lbCordenadasY->Location = System::Drawing::Point(10, 70);
			   this->lbCordenadasY->Name = L"lbCordenadasY";
			   this->lbCordenadasY->Size = System::Drawing::Size(97, 16);
			   this->lbCordenadasY->TabIndex = 10;
			   this->lbCordenadasY->Text = L"Cordenadas Y:";

			   this->lbCordenadasX->AutoSize = true;
			   this->lbCordenadasX->Location = System::Drawing::Point(3, 38);
			   this->lbCordenadasX->Name = L"lbCordenadasX";
			   this->lbCordenadasX->Size = System::Drawing::Size(96, 16);
			   this->lbCordenadasX->TabIndex = 9;
			   this->lbCordenadasX->Text = L"Cordenadas X:";

			   this->pnlDibujar->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			   this->pnlDibujar->Location = System::Drawing::Point(285, 13);
			   this->pnlDibujar->Name = L"pnlDibujar";
			   this->pnlDibujar->Size = System::Drawing::Size(746, 700);
			   this->pnlDibujar->TabIndex = 2;
			   this->pnlDibujar->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmSimuladorTL::pnlDibujar_Paint);

			   this->timer1->Tick += gcnew System::EventHandler(this, &FrmSimuladorTL::timer1_Tick);

			   this->btnRestablecerFigura->Location = System::Drawing::Point(12, 675);
			   this->btnRestablecerFigura->Name = L"btnRestablecerFigura";
			   this->btnRestablecerFigura->Size = System::Drawing::Size(115, 35);
			   this->btnRestablecerFigura->TabIndex = 3;
			   this->btnRestablecerFigura->Text = L"Deshacer";
			   this->btnRestablecerFigura->UseVisualStyleBackColor = true;
			   this->btnRestablecerFigura->Click += gcnew System::EventHandler(this, &FrmSimuladorTL::btnRestablecerFigura_Click);

			   this->btnReiniciar->Location = System::Drawing::Point(135, 675);
			   this->btnReiniciar->Name = L"btnReiniciar";
			   this->btnReiniciar->Size = System::Drawing::Size(115, 35);
			   this->btnReiniciar->TabIndex = 4;
			   this->btnReiniciar->Text = L"Borrar Todo";
			   this->btnReiniciar->UseVisualStyleBackColor = true;
			   this->btnReiniciar->Click += gcnew System::EventHandler(this, &FrmSimuladorTL::btnReiniciar_Click);

			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1043, 734);
			   this->Controls->Add(this->btnReiniciar);
			   this->Controls->Add(this->pnlDibujar);
			   this->Controls->Add(this->btnRestablecerFigura);
			   this->Controls->Add(this->grpHomotecia);
			   this->Controls->Add(this->grpFigura);
			   this->Controls->Add(this->groupBox3);
			   this->Controls->Add(this->groupBox2);
			   this->Name = L"FrmSimuladorTL";
			   this->Text = L"Simulador Computacional de Transformaciones Lineales R2";
			   this->grpHomotecia->ResumeLayout(false);
			   this->grpHomotecia->PerformLayout();
			   this->groupBox2->ResumeLayout(false);
			   this->groupBox2->PerformLayout();
			   this->groupBox3->ResumeLayout(false);
			   this->groupBox3->PerformLayout();
			   this->grpFigura->ResumeLayout(false);
			   this->grpFigura->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion

		   void AjustarCamara() {
			   double maxVal = 9.0;

			   if (figuraBaseOriginal != nullptr) {
				   for (auto p : figuraBaseOriginal->getPuntos()) {
					   if (std::abs(p->getX()) > maxVal) maxVal = std::abs(p->getX());
					   if (std::abs(p->getY()) > maxVal) maxVal = std::abs(p->getY());
				   }
			   }
			   if (figuraActual != nullptr) {
				   for (auto p : figuraActual->getPuntos()) {
					   if (std::abs(p->getX()) > maxVal) maxVal = std::abs(p->getX());
					   if (std::abs(p->getY()) > maxVal) maxVal = std::abs(p->getY());
				   }
			   }

			   maxVal += 1.0;

			   double minDimension = (double)Math::Min(pnlDibujar->Width / 2, pnlDibujar->Height / 2);
			   escalaGrid = minDimension / maxVal;
		   }

	private: void CreateCachedBackground()
	{
		if (pnlDibujar->Width <= 0 || pnlDibujar->Height <= 0) return;

		if (cachedPnlDibujar != nullptr) {
			if (cachedPnlDibujar->Width == pnlDibujar->Width && cachedPnlDibujar->Height == pnlDibujar->Height && cachedEscalaGrid == escalaGrid) {
				return;
			}
			delete cachedPnlDibujar;
			cachedPnlDibujar = nullptr;
		}

		cachedEscalaGrid = escalaGrid;
		cachedPnlDibujar = gcnew Bitmap(pnlDibujar->Width, pnlDibujar->Height);
		Graphics^ g = Graphics::FromImage(cachedPnlDibujar);

		g->Clear(pnlDibujar->BackColor);

		int w = cachedPnlDibujar->Width;
		int h = cachedPnlDibujar->Height;
		int cx = w / 2;
		int cy = h / 2;

		Pen^ pen = gcnew Pen(Color::White, 2);

		g->DrawLine(pen, 0.0f, (float)cy, (float)w, (float)cy);
		g->DrawLine(pen, (float)cx, 0.0f, (float)cx, (float)h);

		DibujarEjesConNumeros(g, w, h);
		delete g;
	}

		   void DibujarRecta(Graphics^ g, int ancho, int alto) {
			   if (!mostrarRecta) return;

			   int centroX = ancho / 2;
			   int centroY = alto / 2;
			   double escala = escalaGrid;

			   double xUnitMin = -static_cast<double>(centroX) / escala;
			   double xUnitMax = static_cast<double>(centroX) / escala;

			   double x1 = xUnitMin;
			   double y1 = reflecM * x1 + reflecB;
			   double x2 = xUnitMax;
			   double y2 = reflecM * x2 + reflecB;

			   float sx1 = static_cast<float>(centroX + x1 * escala);
			   float sy1 = static_cast<float>(centroY - y1 * escala);
			   float sx2 = static_cast<float>(centroX + x2 * escala);
			   float sy2 = static_cast<float>(centroY - y2 * escala);

			   Pen^ penLinea = gcnew Pen(Color::Yellow, 2.0f);
			   penLinea->DashStyle = System::Drawing::Drawing2D::DashStyle::Dash;
			   g->DrawLine(penLinea, sx1, sy1, sx2, sy2);
			   delete penLinea;
		   }

	private: System::Void pnlDibujar_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		AjustarCamara();

		Bitmap^ buffer = gcnew Bitmap(pnlDibujar->Width, pnlDibujar->Height);
		Graphics^ gBuffer = Graphics::FromImage(buffer);

		CreateCachedBackground();
		if (cachedPnlDibujar) {
			gBuffer->DrawImageUnscaled(cachedPnlDibujar, 0, 0);
		}

		DibujarRecta(gBuffer, pnlDibujar->Width, pnlDibujar->Height);

		if (figuraActual != nullptr && dibujador != nullptr) {
			if (figuraBaseOriginal != nullptr) {
				dibujador->DibujarFiguraComparativa(gBuffer, figuraBaseOriginal, figuraActual, escalaGrid, esHomotecia);
			}
			else {
				dibujador->DibujarFiguraNormal(gBuffer, figuraActual, escalaGrid);
			}
		}

		e->Graphics->DrawImageUnscaled(buffer, 0, 0);

		delete gBuffer;
		delete buffer;
	}

		   void DibujarEjesConNumeros(Graphics^ g, int ancho, int alto) {
			   int centroX = ancho / 2;
			   int centroY = alto / 2;
			   double escala = escalaGrid;

			   Pen^ penEjes = gcnew Pen(Color::White, 2.0f);
			   g->DrawLine(penEjes, 0.0f, (float)centroY, (float)ancho, (float)centroY);
			   g->DrawLine(penEjes, (float)centroX, 0.0f, (float)centroX, (float)alto);

			   System::Drawing::Font^ fuente = gcnew System::Drawing::Font("Arial", 8);
			   SolidBrush^ brochaBlanca = gcnew SolidBrush(Color::White);
			   Pen^ penMarcas = gcnew Pen(Color::LightGray, 1.0f);

			   int step = 1;
			   while ((step * escala) < 20.0) {
				   if (step == 1) step = 2;
				   else if (step == 2) step = 5;
				   else if (step == 5) step = 10;
				   else if (step == 10) step = 20;
				   else if (step == 20) step = 50;
				   else if (step == 50) step = 100;
				   else step += 100;
			   }

			   int maxMarcas = (int)((Math::Max(ancho, alto) / 2) / escala) + 1;

			   for (int i = -maxMarcas; i <= maxMarcas; i++) {
				   if (i == 0) continue;

				   if (i % step == 0) {
					   float posX = centroX + (float)(i * escala);
					   if (posX >= 0 && posX <= ancho) {
						   g->DrawLine(penMarcas, posX, (float)(centroY - 4), posX, (float)(centroY + 4));
						   g->DrawString(i.ToString(), fuente, brochaBlanca, posX - 8, centroY + 6);
					   }

					   float posY = centroY - (float)(i * escala);
					   if (posY >= 0 && posY <= alto) {
						   g->DrawLine(penMarcas, (float)(centroX - 4), posY, (float)(centroX + 4), posY);
						   g->DrawString(i.ToString(), fuente, brochaBlanca, centroX + 6, posY - 6);
					   }
				   }
				   else {
					   float posX = centroX + (float)(i * escala);
					   if (posX >= 0 && posX <= ancho && (escala > 5.0)) {
						   g->DrawLine(penMarcas, posX, (float)(centroY - 2), posX, (float)(centroY + 2));
					   }
					   float posY = centroY - (float)(i * escala);
					   if (posY >= 0 && posY <= alto && (escala > 5.0)) {
						   g->DrawLine(penMarcas, (float)(centroX - 2), posY, (float)(centroX + 2), posY);
					   }
				   }
			   }
		   }

		   bool validarCampoRotacion(String^ campoAngulo) {
			   try
			   {
				   double angulo = Double::Parse(campoAngulo, System::Globalization::CultureInfo::InvariantCulture);
				   const double EPS = 1e-9;
				   return (std::abs(angulo) > EPS) && (angulo >= -360.0 && angulo <= 360.0);
			   }
			   catch (Exception^)
			   {
				   Console::WriteLine("Error: La cadena contiene caracteres no numericos.");
			   }
			   return false;
		   }

		   bool validarCampoReHomotencia(String^ factor) {
			   try
			   {
				   double k = Double::Parse(factor, System::Globalization::CultureInfo::InvariantCulture);
				   const double EPS = 1e-9;
				   return (std::abs(k) > EPS);
			   }
			   catch (Exception^ e) {
				   Console::WriteLine("Error: La cadena contiene caracteres no numericos.");
			   }
			   return false;
		   }

		   bool ValidarCompoCordenada(String^ texto) {
			   String^ patron = "^[+-]?\\d+(\\.\\d+)?(,\\s*[+-]?\\d+(\\.\\d+)?)*$";
			   return System::Text::RegularExpressions::Regex::IsMatch(texto, patron);
		   }

		   bool validadarCampoEcuacionLineal(String^ pendiente, String^ coordenadaOrigen) {
			   try
			   {
				   double intPendiente = Double::Parse(pendiente, System::Globalization::CultureInfo::InvariantCulture);
				   double intCoordeanadaOrigen = Double::Parse(coordenadaOrigen, System::Globalization::CultureInfo::InvariantCulture);
				   return true;
			   }
			   catch (Exception^ e) {
				   Console::WriteLine("Error: La cadena contiene caracteres no numericos.");
			   }
			   return false;
		   }

	private: void limpiarFigura(Figura* fig) {
		if (fig && fig->getNumeroPuntos() > 0) {
			auto antiguos = fig->getPuntos();
			for (auto p : antiguos) {
				delete p;
			}
			fig->limpiarPuntos();
		}
	}

	private: System::Boolean incializarPuntos(Figura* figura, String^ coordsX, String^ coordsY) {
		if (figura == nullptr) return false;

		cli::array<String^>^ partesX = coordsX->Split(',');
		cli::array<String^>^ partesY = coordsY->Split(',');

		if (partesX->Length != partesY->Length) {
			MessageBox::Show("El numero de cordenadas no conisiden en ambos campos, se debe tener correcpondencia entre cordenadas.");
			return false;
		}

		limpiarFigura(figura);

		int nCordenadas = partesX->Length;
		try {
			for (int i = 0; i < nCordenadas; i++) {
				double x = Double::Parse(partesX[i]->Trim(), System::Globalization::CultureInfo::InvariantCulture);
				double y = Double::Parse(partesY[i]->Trim(), System::Globalization::CultureInfo::InvariantCulture);
				double yRelative = -y;

				figura->agregarPunto(new Punto(x, yRelative));
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al parsear coordenadas: asegurate del formato y valores numericos.");
			return false;
		}

		int centerX = pnlDibujar->Width / 2;
		int centerY = pnlDibujar->Height / 2;
		figura->setX(centerX);
		figura->setY(centerY);

		return true;
	}

	private: System::Void btnTriangulo_Click(System::Object^ sender, System::EventArgs^ e) {
		txtCordenadasX->Text = "2, 6, 2";
		txtCordenadasY->Text = "2, 2, 6";
		btnDibujarFigura_Click(sender, e);
	}

	private: System::Void btnCuadrado_Click(System::Object^ sender, System::EventArgs^ e) {
		txtCordenadasX->Text = "2, 6, 6, 2";
		txtCordenadasY->Text = "2, 2, 6, 6";
		btnDibujarFigura_Click(sender, e);
	}

	private: System::Void btnDibujarFigura_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ textBoxX = txtCordenadasX->Text;
		String^ textBoxY = txtCordenadasY->Text;

		if (!ValidarCompoCordenada(textBoxX) || !ValidarCompoCordenada(textBoxY)) {
			MessageBox::Show("Datos en el los Compos cordenada No validos. Se debe seguir el formato (1.5, -2, 4.8), por ejemplo");
			return;
		}

		esHomotecia = false;

		incializarPuntos(figuraAnterior, textBoxX, textBoxY);
		incializarPuntos(figuraActual, textBoxX, textBoxY);

		if (figuraBaseOriginal) delete figuraBaseOriginal;
		figuraBaseOriginal = figuraActual->clonarFigura();

		pnlDibujar->Refresh();
	}

		   void guardarEstadoActual() {
			   if (figuraAnterior) delete figuraAnterior;
			   figuraAnterior = figuraActual->clonarFigura();

			   if (figuraBaseOriginal) delete figuraBaseOriginal;
			   figuraBaseOriginal = figuraActual->clonarFigura();
		   }

	private: System::Void btnRotar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ anguloRotacion = this->txtAnguloRotacion->Text;
		bool campoValido = validarCampoRotacion(anguloRotacion);

		if (!campoValido) {
			MessageBox::Show("El angulo de rotacion no es valido");
			return;
		}

		esHomotecia = false;
		guardarEstadoActual();

		double valorAngulo = Double::Parse(anguloRotacion, System::Globalization::CultureInfo::InvariantCulture);
		double incremento = valorAngulo / 24.0;

		Trasformacion* rotarFigura = new Rotacion(figuraActual, incremento);
		this->animacion = new Animacion(rotarFigura, dibujador, 24, 0);

		timer1->Start();
	}

	private: System::Void btnReflejar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->cboEjeReflexion->SelectedIndex == -1 || figuraActual == nullptr) return;

		esHomotecia = false;
		guardarEstadoActual();

		Reflexion* objReflejar = nullptr;

		if (cboEjeReflexion->SelectedIndex == 2) {
			String^ pendiente = this->txtPendiente->Text;
			String^ cordenadaOrigen = this->txtCordenadaOrigen->Text;

			if (!validadarCampoEcuacionLineal(pendiente, cordenadaOrigen)) {
				MessageBox::Show("Pendiente o b invalidos.");
				return;
			}

			double m_unit = Double::Parse(pendiente, System::Globalization::CultureInfo::InvariantCulture);
			double b_unit = Double::Parse(cordenadaOrigen, System::Globalization::CultureInfo::InvariantCulture);

			double m_pix = -m_unit;
			double b_pix = -b_unit;

			objReflejar = new Reflexion(figuraActual, m_pix, b_pix);

			reflecM = m_unit;
			reflecB = b_unit;
			mostrarRecta = true;
		}
		else {
			mostrarRecta = false;
			objReflejar = new Reflexion(figuraActual, this->cboEjeReflexion->SelectedIndex);
		}

		if (objReflejar != nullptr) {
			this->animacion = new Animacion(objReflejar, dibujador, 24, 1);
			timer1->Start();
		}
	}

	private: System::Void btnHomotencia_Click(System::Object^ sender, System::EventArgs^ e) {
		if (figuraActual == nullptr) return;

		String^ strFactor = this->txtFactor->Text;

		if (!validarCampoReHomotencia(strFactor)) {
			MessageBox::Show("El factor de homotecia no es valido. Ingrese un numero distinto de 0.");
			return;
		}

		esHomotecia = true;
		guardarEstadoActual();

		double factorEscala = Double::Parse(strFactor, System::Globalization::CultureInfo::InvariantCulture);

		int tipoEscalado = 0;
		if (rbtnX->Checked) {
			tipoEscalado = 1;
		}
		else if (rbtnY->Checked) {
			tipoEscalado = 2;
		}
		else if (radioButton1->Checked) {
			tipoEscalado = 0;
		}
		else {
			MessageBox::Show("Por favor, seleccione un tipo de homotecia.");
			return;
		}

		Homotecia* objHomotecia = new Homotecia(figuraActual, factorEscala, tipoEscalado);
		if (objHomotecia != nullptr) {
			this->animacion = new Animacion(objHomotecia, dibujador, 24, 1);
			timer1->Start();
		}
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (animacion != nullptr) {
			animacion->animarPaso();
			pnlDibujar->Refresh();

			if (animacion->getPasosRestantes() <= 0) {
				delete animacion;
				animacion = nullptr;
				timer1->Stop();
			}
		}
	}

	private: System::Void btnRestablecerFigura_Click(System::Object^ sender, System::EventArgs^ e) {
		if (figuraAnterior && figuraActual->getNumeroPuntos() > 0) {
			esHomotecia = false;
			TransRestablecer* transRes = new TransRestablecer(figuraActual, figuraAnterior);
			this->animacion = new Animacion(transRes, dibujador, 24, 1);
			timer1->Start();
		}
	}

	private: System::Void btnReiniciar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (animacion != nullptr) {
			timer1->Stop();
			delete animacion;
			animacion = nullptr;
		}
		if (figuraActual != nullptr) limpiarFigura(figuraActual);
		if (figuraAnterior != nullptr) limpiarFigura(figuraAnterior);
		if (figuraBaseOriginal != nullptr) {
			delete figuraBaseOriginal;
			figuraBaseOriginal = nullptr;
		}

		esHomotecia = false;
		mostrarRecta = false;

		txtCordenadasX->Text = "";
		txtCordenadasY->Text = "";
		txtAnguloRotacion->Text = "";
		txtFactor->Text = "";
		txtPendiente->Text = "";
		txtCordenadaOrigen->Text = "";

		pnlDibujar->Refresh();
	}

	private: System::Void cboEjeReflexion_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ selectedOption = cboEjeReflexion->SelectedItem->ToString();

		if ("Recta general" == selectedOption) {
			lbEcuacionRecta->Visible = true;
			lbPendiente->Visible = true;
			lbCordenadaOrigen->Visible = true;
			txtPendiente->Visible = true;
			txtCordenadaOrigen->Visible = true;
		}
		else {
			lbEcuacionRecta->Visible = false;
			lbPendiente->Visible = false;
			txtPendiente->Visible = false;
			txtCordenadaOrigen->Visible = false;
			lbCordenadaOrigen->Visible = false;
			mostrarRecta = false;
		}
	}

	private: System::Void txtAnguloRotacion_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void textCordenadaOrigen_TextChanged(System::Object^ sender, System::EventArgs^ e) {}

	};
}