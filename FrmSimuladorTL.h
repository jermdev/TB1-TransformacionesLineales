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
			modoClick = false;
			reflecM = 0.0;
			reflecB = 0.0;

			int x = pnlDibujar->Width;
			int y = pnlDibujar->Height;

			cordenadaXCentroHototencia = x;
			cordenadaYCentroHototencia = y;

			txtCoordXPHomotencia->Text = Convert::ToString(0);
			txtCoordYPHomotencia->Text = Convert::ToString(0);

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
	private: System::Windows::Forms::Button^ btnDibujarModoClick;
	private: System::Windows::Forms::Button^ btnListo;
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
		bool modoClick;
		double escalaGrid;
		double cachedEscalaGrid;

		double cordenadaXCentroHototencia;
		double cordenadaYCentroHototencia;
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
	private: System::Windows::Forms::Label^ lbPuntoHomotencia;
	private: System::Windows::Forms::TextBox^ txtCoordYPHomotencia;
	private: System::Windows::Forms::TextBox^ txtCoordXPHomotencia;
	private: System::Windows::Forms::Label^ lbCoordYPHomotencia;
	private: System::Windows::Forms::Label^ lbCoordXPHomotencia;
	private: System::Windows::Forms::Label^ lbCentroX;
	private: System::Windows::Forms::Label^ lbCentroY;
	private: System::Windows::Forms::TextBox^ txtCentroX;
	private: System::Windows::Forms::TextBox^ txtCentroY;
	private: System::Windows::Forms::DataGridView^ dgvCoordenadas;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colX;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colY;

		   Animacion* animacion;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->grpHomotecia = (gcnew System::Windows::Forms::GroupBox());
			   this->lbCoordYPHomotencia = (gcnew System::Windows::Forms::Label());
			   this->lbCoordXPHomotencia = (gcnew System::Windows::Forms::Label());
			   this->txtCoordYPHomotencia = (gcnew System::Windows::Forms::TextBox());
			   this->txtCoordXPHomotencia = (gcnew System::Windows::Forms::TextBox());
			   this->lbPuntoHomotencia = (gcnew System::Windows::Forms::Label());
			   this->txtFactor = (gcnew System::Windows::Forms::TextBox());
			   this->lbFactor = (gcnew System::Windows::Forms::Label());
			   this->rbtnY = (gcnew System::Windows::Forms::RadioButton());
			   this->rbtnX = (gcnew System::Windows::Forms::RadioButton());
			   this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			   this->btnHomotencia = (gcnew System::Windows::Forms::Button());
			   this->lbCentroX = (gcnew System::Windows::Forms::Label());
			   this->txtCentroX = (gcnew System::Windows::Forms::TextBox());
			   this->lbCentroY = (gcnew System::Windows::Forms::Label());
			   this->txtCentroY = (gcnew System::Windows::Forms::TextBox());
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
			   this->dgvCoordenadas = (gcnew System::Windows::Forms::DataGridView());
			   this->colX = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->colY = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->btnDibujarFigura = (gcnew System::Windows::Forms::Button());
			   this->btnDibujarModoClick = (gcnew System::Windows::Forms::Button());
			   this->btnListo = (gcnew System::Windows::Forms::Button());
			   this->btnTriangulo = (gcnew System::Windows::Forms::Button());
			   this->btnCuadrado = (gcnew System::Windows::Forms::Button());
			   this->pnlDibujar = (gcnew System::Windows::Forms::Panel());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->btnRestablecerFigura = (gcnew System::Windows::Forms::Button());
			   this->btnReiniciar = (gcnew System::Windows::Forms::Button());
			   this->grpHomotecia->SuspendLayout();
			   this->groupBox2->SuspendLayout();
			   this->groupBox3->SuspendLayout();
			   this->grpFigura->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCoordenadas))->BeginInit();
			   this->SuspendLayout();

			   this->grpHomotecia->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			   this->grpHomotecia->Controls->Add(this->lbCoordYPHomotencia);
			   this->grpHomotecia->Controls->Add(this->lbCoordXPHomotencia);
			   this->grpHomotecia->Controls->Add(this->txtCoordYPHomotencia);
			   this->grpHomotecia->Controls->Add(this->txtCoordXPHomotencia);
			   this->grpHomotecia->Controls->Add(this->lbPuntoHomotencia);
			   this->grpHomotecia->Controls->Add(this->txtFactor);
			   this->grpHomotecia->Controls->Add(this->lbFactor);
			   this->grpHomotecia->Controls->Add(this->rbtnY);
			   this->grpHomotecia->Controls->Add(this->rbtnX);
			   this->grpHomotecia->Controls->Add(this->radioButton1);
			   this->grpHomotecia->Controls->Add(this->btnHomotencia);
			   this->grpHomotecia->Location = System::Drawing::Point(18, 510);
			   this->grpHomotecia->Name = L"grpHomotecia";
			   this->grpHomotecia->Size = System::Drawing::Size(253, 168);
			   this->grpHomotecia->TabIndex = 0;
			   this->grpHomotecia->TabStop = false;
			   this->grpHomotecia->Text = L"Homotecia";

			   this->lbCoordYPHomotencia->AutoSize = true;
			   this->lbCoordYPHomotencia->Location = System::Drawing::Point(186, 40);
			   this->lbCoordYPHomotencia->Name = L"lbCoordYPHomotencia";
			   this->lbCoordYPHomotencia->Size = System::Drawing::Size(19, 16);
			   this->lbCoordYPHomotencia->TabIndex = 11;
			   this->lbCoordYPHomotencia->Text = L"Y:";

			   this->lbCoordXPHomotencia->AutoSize = true;
			   this->lbCoordXPHomotencia->Location = System::Drawing::Point(132, 37);
			   this->lbCoordXPHomotencia->Name = L"lbCoordXPHomotencia";
			   this->lbCoordXPHomotencia->Size = System::Drawing::Size(18, 16);
			   this->lbCoordXPHomotencia->TabIndex = 10;
			   this->lbCoordXPHomotencia->Text = L"X:";

			   this->txtCoordYPHomotencia->Location = System::Drawing::Point(211, 34);
			   this->txtCoordYPHomotencia->Name = L"txtCoordYPHomotencia";
			   this->txtCoordYPHomotencia->Size = System::Drawing::Size(30, 22);
			   this->txtCoordYPHomotencia->TabIndex = 9;

			   this->txtCoordXPHomotencia->Location = System::Drawing::Point(154, 34);
			   this->txtCoordXPHomotencia->Name = L"txtCoordXPHomotencia";
			   this->txtCoordXPHomotencia->Size = System::Drawing::Size(26, 22);
			   this->txtCoordXPHomotencia->TabIndex = 8;

			   this->lbPuntoHomotencia->AutoSize = true;
			   this->lbPuntoHomotencia->Location = System::Drawing::Point(7, 37);
			   this->lbPuntoHomotencia->Name = L"lbPuntoHomotencia";
			   this->lbPuntoHomotencia->Size = System::Drawing::Size(125, 16);
			   this->lbPuntoHomotencia->TabIndex = 7;
			   this->lbPuntoHomotencia->Text = L"Punto Homotecia:";

			   this->txtFactor->Location = System::Drawing::Point(143, 72);
			   this->txtFactor->Name = L"txtFactor";
			   this->txtFactor->Size = System::Drawing::Size(84, 22);
			   this->txtFactor->TabIndex = 6;

			   this->lbFactor->AutoSize = true;
			   this->lbFactor->Location = System::Drawing::Point(7, 72);
			   this->lbFactor->Name = L"lbFactor";
			   this->lbFactor->Size = System::Drawing::Size(48, 16);
			   this->lbFactor->TabIndex = 5;
			   this->lbFactor->Text = L"Factor:";

			   this->rbtnY->AutoSize = true;
			   this->rbtnY->Location = System::Drawing::Point(154, 100);
			   this->rbtnY->Name = L"rbtnY";
			   this->rbtnY->Size = System::Drawing::Size(37, 20);
			   this->rbtnY->TabIndex = 3;
			   this->rbtnY->TabStop = true;
			   this->rbtnY->Text = L"Y";
			   this->rbtnY->UseVisualStyleBackColor = true;

			   this->rbtnX->AutoSize = true;
			   this->rbtnX->Location = System::Drawing::Point(107, 100);
			   this->rbtnX->Name = L"rbtnX";
			   this->rbtnX->Size = System::Drawing::Size(36, 20);
			   this->rbtnX->TabIndex = 2;
			   this->rbtnX->TabStop = true;
			   this->rbtnX->Text = L"X";
			   this->rbtnX->UseVisualStyleBackColor = true;

			   this->radioButton1->AutoSize = true;
			   this->radioButton1->Location = System::Drawing::Point(6, 100);
			   this->radioButton1->Name = L"radioButton1";
			   this->radioButton1->Size = System::Drawing::Size(84, 20);
			   this->radioButton1->TabIndex = 1;
			   this->radioButton1->TabStop = true;
			   this->radioButton1->Text = L"Simetrico";
			   this->radioButton1->UseVisualStyleBackColor = true;

			   this->btnHomotencia->Location = System::Drawing::Point(6, 136);
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
			   this->groupBox2->Location = System::Drawing::Point(12, 225);
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
			   this->groupBox3->Location = System::Drawing::Point(12, 390);
			   this->groupBox3->Name = L"groupBox3";
			   this->groupBox3->Size = System::Drawing::Size(253, 118);
			   this->groupBox3->TabIndex = 1;
			   this->groupBox3->TabStop = false;
			   this->groupBox3->Text = L"Rotacion";

			   this->btnRotar->Location = System::Drawing::Point(6, 73);
			   this->btnRotar->Name = L"btnRotar";
			   this->btnRotar->Size = System::Drawing::Size(241, 26);
			   this->btnRotar->TabIndex = 9;
			   this->btnRotar->Text = L"Rotar";
			   this->btnRotar->UseVisualStyleBackColor = true;
			   this->btnRotar->Click += gcnew System::EventHandler(this, &FrmSimuladorTL::btnRotar_Click);

			   this->lbAnguloRotacion->AutoSize = true;
			   this->lbAnguloRotacion->Location = System::Drawing::Point(9, 38);
			   this->lbAnguloRotacion->Name = L"lbAnguloRotacion";
			   this->lbAnguloRotacion->Size = System::Drawing::Size(125, 16);
			   this->lbAnguloRotacion->TabIndex = 8;
			   this->lbAnguloRotacion->Text = L"Angulo de Rotacion";

			   this->txtAnguloRotacion->Location = System::Drawing::Point(150, 32);
			   this->txtAnguloRotacion->Name = L"txtAnguloRotacion";
			   this->txtAnguloRotacion->Size = System::Drawing::Size(84, 22);
			   this->txtAnguloRotacion->TabIndex = 7;

			   this->grpFigura->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			   this->grpFigura->Controls->Add(this->dgvCoordenadas);
			   this->grpFigura->Controls->Add(this->btnDibujarFigura);
			   this->grpFigura->Controls->Add(this->btnDibujarModoClick);
			   this->grpFigura->Controls->Add(this->btnListo);
			   this->grpFigura->Controls->Add(this->btnTriangulo);
			   this->grpFigura->Controls->Add(this->btnCuadrado);
			   this->grpFigura->Location = System::Drawing::Point(12, 13);
			   this->grpFigura->Name = L"grpFigura";
			   this->grpFigura->Size = System::Drawing::Size(253, 205);
			   this->grpFigura->TabIndex = 1;
			   this->grpFigura->TabStop = false;
			   this->grpFigura->Text = L"Figura";

			   this->dgvCoordenadas->AllowUserToResizeColumns = false;
			   this->dgvCoordenadas->AllowUserToResizeRows = false;
			   this->dgvCoordenadas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			   this->dgvCoordenadas->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				   this->colX,
					   this->colY
			   });
			   this->dgvCoordenadas->Location = System::Drawing::Point(66, 20);
			   this->dgvCoordenadas->Name = L"dgvCoordenadas";
			   this->dgvCoordenadas->RowHeadersVisible = false;
			   this->dgvCoordenadas->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			   this->dgvCoordenadas->BackgroundColor = System::Drawing::Color::LightGray;
			   this->dgvCoordenadas->Size = System::Drawing::Size(120, 85);
			   this->dgvCoordenadas->TabIndex = 16;

			   this->colX->HeaderText = L"X";
			   this->colX->MinimumWidth = 6;
			   this->colX->Name = L"colX";
			   this->colX->Width = 50;

			   this->colY->HeaderText = L"Y";
			   this->colY->MinimumWidth = 6;
			   this->colY->Name = L"colY";
			   this->colY->Width = 50;

			   this->btnDibujarModoClick->Location = System::Drawing::Point(6, 110);
			   this->btnDibujarModoClick->Name = L"btnDibujarModoClick";
			   this->btnDibujarModoClick->Size = System::Drawing::Size(115, 26);
			   this->btnDibujarModoClick->TabIndex = 17;
			   this->btnDibujarModoClick->Text = L"Modo Clics";
			   this->btnDibujarModoClick->UseVisualStyleBackColor = true;
			   this->btnDibujarModoClick->Click += gcnew System::EventHandler(this, &FrmSimuladorTL::btnDibujarModoClick_Click);

			   this->btnDibujarFigura->Location = System::Drawing::Point(132, 110);
			   this->btnDibujarFigura->Name = L"btnDibujarFigura";
			   this->btnDibujarFigura->Size = System::Drawing::Size(115, 26);
			   this->btnDibujarFigura->TabIndex = 13;
			   this->btnDibujarFigura->Text = L"Dibujar Figura";
			   this->btnDibujarFigura->UseVisualStyleBackColor = true;
			   this->btnDibujarFigura->Click += gcnew System::EventHandler(this, &FrmSimuladorTL::btnDibujarFigura_Click);

			   this->btnTriangulo->Location = System::Drawing::Point(6, 140);
			   this->btnTriangulo->Name = L"btnTriangulo";
			   this->btnTriangulo->Size = System::Drawing::Size(115, 26);
			   this->btnTriangulo->TabIndex = 14;
			   this->btnTriangulo->Text = L"Triangulo";
			   this->btnTriangulo->UseVisualStyleBackColor = true;
			   this->btnTriangulo->Click += gcnew System::EventHandler(this, &FrmSimuladorTL::btnTriangulo_Click);

			   this->btnCuadrado->Location = System::Drawing::Point(132, 140);
			   this->btnCuadrado->Name = L"btnCuadrado";
			   this->btnCuadrado->Size = System::Drawing::Size(115, 26);
			   this->btnCuadrado->TabIndex = 15;
			   this->btnCuadrado->Text = L"Cuadrado";
			   this->btnCuadrado->UseVisualStyleBackColor = true;
			   this->btnCuadrado->Click += gcnew System::EventHandler(this, &FrmSimuladorTL::btnCuadrado_Click);

			   this->btnListo->Location = System::Drawing::Point(6, 172);
			   this->btnListo->Name = L"btnListo";
			   this->btnListo->Size = System::Drawing::Size(241, 26);
			   this->btnListo->TabIndex = 18;
			   this->btnListo->Text = L"LISTO (Terminar Clics)";
			   this->btnListo->UseVisualStyleBackColor = true;
			   this->btnListo->Visible = false;
			   this->btnListo->Click += gcnew System::EventHandler(this, &FrmSimuladorTL::btnListo_Click);

			   this->pnlDibujar->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			   this->pnlDibujar->Location = System::Drawing::Point(285, 13);
			   this->pnlDibujar->Name = L"pnlDibujar";
			   this->pnlDibujar->Size = System::Drawing::Size(746, 700);
			   this->pnlDibujar->TabIndex = 2;
			   this->pnlDibujar->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmSimuladorTL::pnlDibujar_Paint);
			   this->pnlDibujar->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &FrmSimuladorTL::pnlDibujar_MouseClick);

			   this->timer1->Tick += gcnew System::EventHandler(this, &FrmSimuladorTL::timer1_Tick);

			   this->btnRestablecerFigura->Location = System::Drawing::Point(12, 685);
			   this->btnRestablecerFigura->Name = L"btnRestablecerFigura";
			   this->btnRestablecerFigura->Size = System::Drawing::Size(115, 35);
			   this->btnRestablecerFigura->TabIndex = 3;
			   this->btnRestablecerFigura->Text = L"Deshacer";
			   this->btnRestablecerFigura->UseVisualStyleBackColor = true;
			   this->btnRestablecerFigura->Click += gcnew System::EventHandler(this, &FrmSimuladorTL::btnRestablecerFigura_Click);

			   this->btnReiniciar->Location = System::Drawing::Point(135, 685);
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
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCoordenadas))->EndInit();
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
		delete pen;
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

		if (modoClick) {
			SolidBrush^ brushTemp = gcnew SolidBrush(Color::Red);
			int cx = pnlDibujar->Width / 2;
			int cy = pnlDibujar->Height / 2;

			for (int i = 0; i < dgvCoordenadas->Rows->Count; i++) {
				if (dgvCoordenadas->Rows[i]->IsNewRow) continue;
				Object^ valX = dgvCoordenadas->Rows[i]->Cells[0]->Value;
				Object^ valY = dgvCoordenadas->Rows[i]->Cells[1]->Value;

				if (valX != nullptr && valY != nullptr) {
					try {
						double x = Double::Parse(valX->ToString(), System::Globalization::CultureInfo::InvariantCulture);
						double y = Double::Parse(valY->ToString(), System::Globalization::CultureInfo::InvariantCulture);

						float px = (float)(cx + x * escalaGrid);
						float py = (float)(cy - y * escalaGrid);

						gBuffer->FillEllipse(brushTemp, px - 3.0f, py - 3.0f, 6.0f, 6.0f);
					}
					catch (...) {}
				}
			}
			delete brushTemp;
		}
		else if (figuraActual != nullptr && dibujador != nullptr) {
			if (figuraBaseOriginal != nullptr) {
				dibujador->DibujarFiguraComparativa(gBuffer, figuraBaseOriginal, figuraActual, escalaGrid, esHomotecia, cordenadaXCentroHototencia, cordenadaYCentroHototencia);
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

			   int step = 1;
			   if (escalaGrid > 0) {
				   double unitsPerLabel = 40.0 / escalaGrid;
				   if (unitsPerLabel > 1.0) {
					   if (unitsPerLabel <= 2.0) step = 2;
					   else if (unitsPerLabel <= 5.0) step = 5;
					   else if (unitsPerLabel <= 10.0) step = 10;
					   else if (unitsPerLabel <= 20.0) step = 20;
					   else if (unitsPerLabel <= 50.0) step = 50;
					   else if (unitsPerLabel <= 100.0) step = 100;
					   else if (unitsPerLabel <= 200.0) step = 200;
					   else if (unitsPerLabel <= 500.0) step = 500;
					   else step = 1000;
				   }
			   }

			   int maxUnitsX = (int)((ancho / 2) / escalaGrid) + 1;
			   int maxUnitsY = (int)((alto / 2) / escalaGrid) + 1;
			   int maxUnits = Math::Max(maxUnitsX, maxUnitsY);

			   System::Drawing::Font^ fuente = gcnew System::Drawing::Font("Arial", 8);
			   SolidBrush^ brochaBlanca = gcnew SolidBrush(Color::White);
			   Pen^ penMarcas = gcnew Pen(Color::LightGray, 1.0f);

			   for (int i = step; i <= maxUnits; i += step) {
				   int posX1 = centroX + (int)(i * escalaGrid);
				   int posX2 = centroX - (int)(i * escalaGrid);

				   g->DrawLine(penMarcas, posX1, centroY - 3, posX1, centroY + 3);
				   g->DrawString(i.ToString(), fuente, brochaBlanca, posX1 - 6, centroY + 5);

				   g->DrawLine(penMarcas, posX2, centroY - 3, posX2, centroY + 3);
				   g->DrawString((-i).ToString(), fuente, brochaBlanca, posX2 - 6, centroY + 5);
			   }

			   for (int i = step; i <= maxUnits; i += step) {
				   int posY1 = centroY - (int)(i * escalaGrid);
				   int posY2 = centroY + (int)(i * escalaGrid);

				   g->DrawLine(penMarcas, centroX - 3, posY1, centroX + 3, posY1);
				   g->DrawString(i.ToString(), fuente, brochaBlanca, centroX + 5, posY1 - 6);

				   g->DrawLine(penMarcas, centroX - 3, posY2, centroX + 3, posY2);
				   g->DrawString((-i).ToString(), fuente, brochaBlanca, centroX + 5, posY2 - 6);
			   }

			   delete fuente;
			   delete brochaBlanca;
			   delete penMarcas;
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

	private: System::Void btnDibujarModoClick_Click(System::Object^ sender, System::EventArgs^ e) {
		modoClick = true;
		esHomotecia = false;
		btnListo->Visible = true;
		dgvCoordenadas->Rows->Clear();
		if (figuraActual != nullptr) limpiarFigura(figuraActual);
		if (figuraAnterior != nullptr) limpiarFigura(figuraAnterior);
		if (figuraBaseOriginal != nullptr) { delete figuraBaseOriginal; figuraBaseOriginal = nullptr; }
		pnlDibujar->Invalidate();
	}

	private: System::Void btnListo_Click(System::Object^ sender, System::EventArgs^ e) {
		if (modoClick) {
			modoClick = false;
			btnListo->Visible = false;
			btnDibujarFigura_Click(nullptr, nullptr);
		}
	}

	private: System::Void pnlDibujar_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (modoClick) {
			if (e->Button == System::Windows::Forms::MouseButtons::Left) {
				int centerX = pnlDibujar->Width / 2;
				int centerY = pnlDibujar->Height / 2;

				double x_log = Math::Round((double)(e->X - centerX) / escalaGrid, 2);
				double y_log = Math::Round((double)(centerY - e->Y) / escalaGrid, 2);

				dgvCoordenadas->Rows->Add(x_log.ToString(System::Globalization::CultureInfo::InvariantCulture),
					y_log.ToString(System::Globalization::CultureInfo::InvariantCulture));
				pnlDibujar->Invalidate();
			}
			else if (e->Button == System::Windows::Forms::MouseButtons::Right) {
				modoClick = false;
				btnListo->Visible = false;
				btnDibujarFigura_Click(nullptr, nullptr);
			}
		}
	}

	private: System::Void btnTriangulo_Click(System::Object^ sender, System::EventArgs^ e) {
		modoClick = false;
		btnListo->Visible = false;
		dgvCoordenadas->Rows->Clear();
		dgvCoordenadas->Rows->Add("2", "2");
		dgvCoordenadas->Rows->Add("6", "2");
		dgvCoordenadas->Rows->Add("2", "6");
		btnDibujarFigura_Click(sender, e);
	}

	private: System::Void btnCuadrado_Click(System::Object^ sender, System::EventArgs^ e) {
		modoClick = false;
		btnListo->Visible = false;
		dgvCoordenadas->Rows->Clear();
		dgvCoordenadas->Rows->Add("2", "2");
		dgvCoordenadas->Rows->Add("6", "2");
		dgvCoordenadas->Rows->Add("6", "6");
		dgvCoordenadas->Rows->Add("2", "6");
		btnDibujarFigura_Click(sender, e);
	}

	private: System::Void btnDibujarFigura_Click(System::Object^ sender, System::EventArgs^ e) {
		modoClick = false;
		esHomotecia = false;
		btnListo->Visible = false;

		limpiarFigura(figuraAnterior);
		limpiarFigura(figuraActual);

		int centerX = pnlDibujar->Width / 2;
		int centerY = pnlDibujar->Height / 2;
		figuraAnterior->setX(centerX);
		figuraAnterior->setY(centerY);
		figuraActual->setX(centerX);
		figuraActual->setY(centerY);

		for (int i = 0; i < dgvCoordenadas->Rows->Count; i++) {
			if (dgvCoordenadas->Rows[i]->IsNewRow) continue;

			Object^ valX = dgvCoordenadas->Rows[i]->Cells[0]->Value;
			Object^ valY = dgvCoordenadas->Rows[i]->Cells[1]->Value;

			if (valX != nullptr && valY != nullptr) {
				try {
					double x = Double::Parse(valX->ToString(), System::Globalization::CultureInfo::InvariantCulture);
					double y = Double::Parse(valY->ToString(), System::Globalization::CultureInfo::InvariantCulture);
					double yRelative = -y;

					figuraAnterior->agregarPunto(new Punto(x, yRelative));
					figuraActual->agregarPunto(new Punto(x, yRelative));
				}
				catch (...) {
					MessageBox::Show("Valor invalido en la tabla de coordenadas.");
					return;
				}
			}
		}

		if (figuraActual->getNumeroPuntos() < 2) {
			return;
		}

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
		modoClick = false;
		btnListo->Visible = false;
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
		modoClick = false;
		btnListo->Visible = false;
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
		modoClick = false;
		btnListo->Visible = false;
		guardarEstadoActual();

		double factorEscala = Double::Parse(strFactor, System::Globalization::CultureInfo::InvariantCulture);
		double centroHomotenciaX = Convert::ToDouble(txtCoordXPHomotencia->Text);
		double centroHomotenciaY = Convert::ToDouble(txtCoordYPHomotencia->Text);

		this->cordenadaXCentroHototencia = centroHomotenciaX * escalaGrid + figuraActual->getX();
		this->cordenadaYCentroHototencia = -centroHomotenciaY * escalaGrid + figuraActual->getY();

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

		Homotecia* objHomotecia = new Homotecia(figuraActual, factorEscala, tipoEscalado, centroHomotenciaX, centroHomotenciaY);
		if (objHomotecia != nullptr) {
			this->animacion = new Animacion(objHomotecia, dibujador, 24, 1);
			timer1->Start();
		}
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (animacion != nullptr) {

			animacion->animarPaso();

			pnlDibujar->Invalidate();
			pnlDibujar->Update();

			if (animacion->getPasosRestantes() <= 0) {

				pnlDibujar->Invalidate();
				pnlDibujar->Update();

				delete animacion;
				animacion = nullptr;

				timer1->Stop();
			}
		}
	}

	private: System::Void btnRestablecerFigura_Click(System::Object^ sender, System::EventArgs^ e) {
		if (figuraAnterior && figuraActual->getNumeroPuntos() > 0) {
			esHomotecia = false;
			modoClick = false;
			btnListo->Visible = false;

			if (figuraBaseOriginal) delete figuraBaseOriginal;
			figuraBaseOriginal = figuraAnterior->clonarFigura();

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
		modoClick = false;
		btnListo->Visible = false;

		dgvCoordenadas->Rows->Clear();
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

	};
}