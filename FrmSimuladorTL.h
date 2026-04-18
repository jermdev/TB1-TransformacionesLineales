#pragma once

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
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Panel^ pnlFondo;

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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->pnlFondo = (gcnew System::Windows::Forms::Panel());
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
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->groupBox1->Location = System::Drawing::Point(12, 13);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(253, 142);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->groupBox2->Location = System::Drawing::Point(12, 194);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(253, 142);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"groupBox2";
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->groupBox3->Location = System::Drawing::Point(12, 393);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(253, 142);
			this->groupBox3->TabIndex = 1;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"groupBox3";
			// 
			// groupBox4
			// 
			this->groupBox4->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->groupBox4->Location = System::Drawing::Point(12, 571);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(253, 142);
			this->groupBox4->TabIndex = 1;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"groupBox4";
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
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pnlMostrarFigura);
			this->Controls->Add(this->pnlFondo);
			this->Name = L"FrmSimuladorTL";
			this->Text = L"FrmSimuladorTL";
			this->ResumeLayout(false);

		}
#pragma endregion


	};
}
