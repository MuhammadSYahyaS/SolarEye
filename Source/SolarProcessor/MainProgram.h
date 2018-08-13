#pragma once

#include "TheProcessors.h"
#include <opencv2\opencv.hpp>

cv::Mat frame, img;
cv::VideoCapture capture;
vector<cv::Vec3f> matahari; //vektor untuk menyimpan variabel koordinat x pusat, koordinat y pusat, dan r matahari
double s, D;

bool errorStatus;

namespace SolarProcessor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainProgram
	/// </summary>
	public ref class MainProgram : public System::Windows::Forms::Form
	{
	public:
		MainProgram(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainProgram()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonOpen;
	protected:
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::PictureBox^  pictureBoxCitra;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Button^  buttonPlay;
	private: System::Windows::Forms::Button^  buttonPause;


	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  LabelTime;
	private: System::Windows::Forms::ToolStripStatusLabel^  LabelFrame;
	private: System::Windows::Forms::ToolStripStatusLabel^  LabelCodec;
	private: System::Windows::Forms::ToolStripStatusLabel^  LabelRes;
	private: System::Windows::Forms::ToolStripStatusLabel^  LabelFPS;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  textBoxdist;
	private: System::Windows::Forms::TextBox^  textBoxDCalc;
	private: System::Windows::Forms::TextBox^  textBoxDdet;

	private: System::Windows::Forms::Button^  buttonAbout;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TextBox^  textBoxRatio;
	private: System::Windows::Forms::TextBox^  textBoxXa;
	private: System::Windows::Forms::TextBox^  textBoxXp;



	private: System::Windows::Forms::TextBox^  textBoxYa;
	private: System::Windows::Forms::TextBox^  textBoxRa;
	private: System::Windows::Forms::TextBox^  textBoxTa;



	private: System::Windows::Forms::TextBox^  textBoxYp;
	private: System::Windows::Forms::TextBox^  textBoxRp;
	private: System::Windows::Forms::TextBox^  textBoxTp;

	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownE;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownC;
	private: System::Windows::Forms::ToolStripStatusLabel^  LabelErrorSun;











	private: System::ComponentModel::IContainer^  components;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainProgram::typeid));
			this->buttonOpen = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBoxCitra = (gcnew System::Windows::Forms::PictureBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->buttonPlay = (gcnew System::Windows::Forms::Button());
			this->buttonPause = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->LabelTime = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->LabelFrame = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->LabelCodec = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->LabelRes = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->LabelFPS = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->LabelErrorSun = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBoxdist = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDCalc = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDdet = (gcnew System::Windows::Forms::TextBox());
			this->buttonAbout = (gcnew System::Windows::Forms::Button());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->textBoxRatio = (gcnew System::Windows::Forms::TextBox());
			this->textBoxXa = (gcnew System::Windows::Forms::TextBox());
			this->textBoxXp = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYa = (gcnew System::Windows::Forms::TextBox());
			this->textBoxRa = (gcnew System::Windows::Forms::TextBox());
			this->textBoxTa = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYp = (gcnew System::Windows::Forms::TextBox());
			this->textBoxRp = (gcnew System::Windows::Forms::TextBox());
			this->textBoxTp = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->numericUpDownE = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownC = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCitra))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->statusStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownE))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownC))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonOpen
			// 
			this->buttonOpen->Location = System::Drawing::Point(12, 378);
			this->buttonOpen->Name = L"buttonOpen";
			this->buttonOpen->Size = System::Drawing::Size(75, 23);
			this->buttonOpen->TabIndex = 0;
			this->buttonOpen->Text = L"Open";
			this->buttonOpen->UseVisualStyleBackColor = true;
			this->buttonOpen->Click += gcnew System::EventHandler(this, &MainProgram::buttonOpen_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"MP4|*.mp4";
			this->openFileDialog1->InitialDirectory = L".";
			// 
			// pictureBoxCitra
			// 
			this->pictureBoxCitra->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pictureBoxCitra->Location = System::Drawing::Point(12, 12);
			this->pictureBoxCitra->Name = L"pictureBoxCitra";
			this->pictureBoxCitra->Size = System::Drawing::Size(640, 360);
			this->pictureBoxCitra->TabIndex = 1;
			this->pictureBoxCitra->TabStop = false;
			// 
			// trackBar1
			// 
			this->trackBar1->Enabled = false;
			this->trackBar1->Location = System::Drawing::Point(151, 378);
			this->trackBar1->Maximum = 20;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(501, 45);
			this->trackBar1->TabIndex = 2;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MainProgram::trackBar1_Scroll);
			// 
			// buttonPlay
			// 
			this->buttonPlay->Enabled = false;
			this->buttonPlay->Font = (gcnew System::Drawing::Font(L"Wingdings 3", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->buttonPlay->Location = System::Drawing::Point(93, 378);
			this->buttonPlay->Name = L"buttonPlay";
			this->buttonPlay->Size = System::Drawing::Size(23, 23);
			this->buttonPlay->TabIndex = 3;
			this->buttonPlay->Text = L"u";
			this->buttonPlay->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->buttonPlay->UseVisualStyleBackColor = true;
			this->buttonPlay->Click += gcnew System::EventHandler(this, &MainProgram::buttonPlay_Click);
			// 
			// buttonPause
			// 
			this->buttonPause->Enabled = false;
			this->buttonPause->Font = (gcnew System::Drawing::Font(L"Wingdings 3", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->buttonPause->Location = System::Drawing::Point(122, 378);
			this->buttonPause->Name = L"buttonPause";
			this->buttonPause->Size = System::Drawing::Size(23, 23);
			this->buttonPause->TabIndex = 4;
			this->buttonPause->Text = L"¯¯";
			this->buttonPause->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->buttonPause->UseVisualStyleBackColor = true;
			this->buttonPause->Click += gcnew System::EventHandler(this, &MainProgram::buttonPause_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MainProgram::timer1_Tick);
			// 
			// statusStrip1
			// 
			this->statusStrip1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->LabelTime, this->LabelFrame,
					this->LabelCodec, this->LabelRes, this->LabelFPS, this->LabelErrorSun
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 589);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(664, 22);
			this->statusStrip1->SizingGrip = false;
			this->statusStrip1->TabIndex = 5;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// LabelTime
			// 
			this->LabelTime->Name = L"LabelTime";
			this->LabelTime->Size = System::Drawing::Size(0, 17);
			// 
			// LabelFrame
			// 
			this->LabelFrame->Name = L"LabelFrame";
			this->LabelFrame->Size = System::Drawing::Size(0, 17);
			// 
			// LabelCodec
			// 
			this->LabelCodec->Name = L"LabelCodec";
			this->LabelCodec->Size = System::Drawing::Size(0, 17);
			// 
			// LabelRes
			// 
			this->LabelRes->Name = L"LabelRes";
			this->LabelRes->Size = System::Drawing::Size(0, 17);
			// 
			// LabelFPS
			// 
			this->LabelFPS->Name = L"LabelFPS";
			this->LabelFPS->Size = System::Drawing::Size(0, 17);
			// 
			// LabelErrorSun
			// 
			this->LabelErrorSun->Name = L"LabelErrorSun";
			this->LabelErrorSun->Size = System::Drawing::Size(160, 17);
			this->LabelErrorSun->Text = L"Error : >1 or no sun detected!";
			this->LabelErrorSun->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 511);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(155, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Sun apparent diameter (calc.) =";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 410);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Video date :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 537);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(177, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Sun apparent diameter (detected) = ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(334, 410);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(134, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Sun deviation from center :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(401, 432);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(26, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"X = ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(401, 458);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(26, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Y = ";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(343, 432);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(57, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Cartesian :";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(400, 484);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(27, 13);
			this->label8->TabIndex = 13;
			this->label8->Text = L"R = ";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(402, 510);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(25, 13);
			this->label9->TabIndex = 14;
			this->label9->Text = L"θ = ";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(343, 484);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(55, 13);
			this->label10->TabIndex = 15;
			this->label10->Text = L"Radial     :";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Checked = false;
			this->dateTimePicker1->CustomFormat = L"dd-MM-yyyy";
			this->dateTimePicker1->Enabled = false;
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(78, 407);
			this->dateTimePicker1->MaxDate = System::DateTime(2100, 12, 31, 0, 0, 0, 0);
			this->dateTimePicker1->MinDate = System::DateTime(1900, 1, 1, 0, 0, 0, 0);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(96, 20);
			this->dateTimePicker1->TabIndex = 16;
			this->dateTimePicker1->Value = System::DateTime(2017, 5, 27, 12, 0, 0, 0);
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &MainProgram::dateTimePicker1_ValueChanged);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(531, 510);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(25, 13);
			this->label12->TabIndex = 21;
			this->label12->Text = L"θ = ";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(529, 484);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(27, 13);
			this->label13->TabIndex = 20;
			this->label13->Text = L"R = ";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(530, 458);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(26, 13);
			this->label15->TabIndex = 18;
			this->label15->Text = L"Y = ";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(530, 432);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(26, 13);
			this->label16->TabIndex = 17;
			this->label16->Text = L"X = ";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(12, 485);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(78, 13);
			this->label11->TabIndex = 22;
			this->label11->Text = L"Sun distance =";
			// 
			// textBoxdist
			// 
			this->textBoxdist->Location = System::Drawing::Point(96, 482);
			this->textBoxdist->Name = L"textBoxdist";
			this->textBoxdist->ReadOnly = true;
			this->textBoxdist->Size = System::Drawing::Size(125, 20);
			this->textBoxdist->TabIndex = 23;
			// 
			// textBoxDCalc
			// 
			this->textBoxDCalc->Location = System::Drawing::Point(173, 508);
			this->textBoxDCalc->Name = L"textBoxDCalc";
			this->textBoxDCalc->ReadOnly = true;
			this->textBoxDCalc->Size = System::Drawing::Size(135, 20);
			this->textBoxDCalc->TabIndex = 24;
			// 
			// textBoxDdet
			// 
			this->textBoxDdet->Location = System::Drawing::Point(195, 534);
			this->textBoxDdet->Name = L"textBoxDdet";
			this->textBoxDdet->ReadOnly = true;
			this->textBoxDdet->Size = System::Drawing::Size(135, 20);
			this->textBoxDdet->TabIndex = 25;
			// 
			// buttonAbout
			// 
			this->buttonAbout->Location = System::Drawing::Point(577, 558);
			this->buttonAbout->Name = L"buttonAbout";
			this->buttonAbout->Size = System::Drawing::Size(75, 23);
			this->buttonAbout->TabIndex = 26;
			this->buttonAbout->Text = L"About";
			this->buttonAbout->UseVisualStyleBackColor = true;
			this->buttonAbout->Click += gcnew System::EventHandler(this, &MainProgram::buttonAbout_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(12, 563);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(146, 13);
			this->label14->TabIndex = 27;
			this->label14->Text = L"Sun apparent diameter ratio =";
			// 
			// textBoxRatio
			// 
			this->textBoxRatio->Location = System::Drawing::Point(164, 560);
			this->textBoxRatio->Name = L"textBoxRatio";
			this->textBoxRatio->ReadOnly = true;
			this->textBoxRatio->Size = System::Drawing::Size(135, 20);
			this->textBoxRatio->TabIndex = 28;
			// 
			// textBoxXa
			// 
			this->textBoxXa->Location = System::Drawing::Point(433, 429);
			this->textBoxXa->Name = L"textBoxXa";
			this->textBoxXa->ReadOnly = true;
			this->textBoxXa->Size = System::Drawing::Size(90, 20);
			this->textBoxXa->TabIndex = 29;
			// 
			// textBoxXp
			// 
			this->textBoxXp->Location = System::Drawing::Point(562, 429);
			this->textBoxXp->Name = L"textBoxXp";
			this->textBoxXp->ReadOnly = true;
			this->textBoxXp->Size = System::Drawing::Size(90, 20);
			this->textBoxXp->TabIndex = 30;
			// 
			// textBoxYa
			// 
			this->textBoxYa->Location = System::Drawing::Point(433, 455);
			this->textBoxYa->Name = L"textBoxYa";
			this->textBoxYa->ReadOnly = true;
			this->textBoxYa->Size = System::Drawing::Size(90, 20);
			this->textBoxYa->TabIndex = 31;
			// 
			// textBoxRa
			// 
			this->textBoxRa->Location = System::Drawing::Point(433, 481);
			this->textBoxRa->Name = L"textBoxRa";
			this->textBoxRa->ReadOnly = true;
			this->textBoxRa->Size = System::Drawing::Size(90, 20);
			this->textBoxRa->TabIndex = 32;
			// 
			// textBoxTa
			// 
			this->textBoxTa->Location = System::Drawing::Point(433, 507);
			this->textBoxTa->Name = L"textBoxTa";
			this->textBoxTa->ReadOnly = true;
			this->textBoxTa->Size = System::Drawing::Size(90, 20);
			this->textBoxTa->TabIndex = 33;
			// 
			// textBoxYp
			// 
			this->textBoxYp->Location = System::Drawing::Point(562, 455);
			this->textBoxYp->Name = L"textBoxYp";
			this->textBoxYp->ReadOnly = true;
			this->textBoxYp->Size = System::Drawing::Size(90, 20);
			this->textBoxYp->TabIndex = 34;
			// 
			// textBoxRp
			// 
			this->textBoxRp->Location = System::Drawing::Point(562, 481);
			this->textBoxRp->Name = L"textBoxRp";
			this->textBoxRp->ReadOnly = true;
			this->textBoxRp->Size = System::Drawing::Size(90, 20);
			this->textBoxRp->TabIndex = 35;
			// 
			// textBoxTp
			// 
			this->textBoxTp->Location = System::Drawing::Point(562, 507);
			this->textBoxTp->Name = L"textBoxTp";
			this->textBoxTp->ReadOnly = true;
			this->textBoxTp->Size = System::Drawing::Size(90, 20);
			this->textBoxTp->TabIndex = 36;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(12, 433);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(152, 13);
			this->label17->TabIndex = 38;
			this->label17->Text = L"Sun edge detection treshold = ";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(12, 458);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(158, 13);
			this->label18->TabIndex = 39;
			this->label18->Text = L"Sun center detection treshold = ";
			// 
			// numericUpDownE
			// 
			this->numericUpDownE->Enabled = false;
			this->numericUpDownE->Location = System::Drawing::Point(170, 431);
			this->numericUpDownE->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->numericUpDownE->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDownE->Name = L"numericUpDownE";
			this->numericUpDownE->Size = System::Drawing::Size(40, 20);
			this->numericUpDownE->TabIndex = 40;
			this->numericUpDownE->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 127, 0, 0, 0 });
			this->numericUpDownE->ValueChanged += gcnew System::EventHandler(this, &MainProgram::numericUpDownE_ValueChanged);
			// 
			// numericUpDownC
			// 
			this->numericUpDownC->Enabled = false;
			this->numericUpDownC->Location = System::Drawing::Point(176, 456);
			this->numericUpDownC->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->numericUpDownC->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDownC->Name = L"numericUpDownC";
			this->numericUpDownC->Size = System::Drawing::Size(40, 20);
			this->numericUpDownC->TabIndex = 41;
			this->numericUpDownC->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->numericUpDownC->ValueChanged += gcnew System::EventHandler(this, &MainProgram::numericUpDownC_ValueChanged);
			// 
			// MainProgram
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(664, 611);
			this->Controls->Add(this->numericUpDownC);
			this->Controls->Add(this->numericUpDownE);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->textBoxTp);
			this->Controls->Add(this->textBoxRp);
			this->Controls->Add(this->textBoxYp);
			this->Controls->Add(this->textBoxTa);
			this->Controls->Add(this->textBoxRa);
			this->Controls->Add(this->textBoxYa);
			this->Controls->Add(this->textBoxXp);
			this->Controls->Add(this->textBoxXa);
			this->Controls->Add(this->textBoxRatio);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->buttonAbout);
			this->Controls->Add(this->textBoxDdet);
			this->Controls->Add(this->textBoxDCalc);
			this->Controls->Add(this->textBoxdist);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->buttonPause);
			this->Controls->Add(this->buttonPlay);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->pictureBoxCitra);
			this->Controls->Add(this->buttonOpen);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MainProgram";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"SolarEye";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCitra))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownE))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownC))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		std::string MarshalString(System::String ^ s) {
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			std::string os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
			return os;
		}
		void DrawFrame(void){
			img = deteksiMatahari(frame, (int)numericUpDownE->Value, (int)numericUpDownC->Value, &errorStatus, &matahari);
			pictureBoxCitra->Image = gcnew System::Drawing::Bitmap(img.cols, img.rows, img.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) img.ptr()); //menampilkan frame yang telah dikonversi menjadi bitmap ke picture box
			pictureBoxCitra->Refresh(); //memuat ulang picture box
			if (errorStatus == 1){
				LabelErrorSun->Visible = 1;
				textBoxDdet->Text = "Error!";
				textBoxRatio->Text = "Error!";
				textBoxXa->Text = "Error!";
				textBoxXp->Text = "Error!";
				textBoxYa->Text = "Error!";
				textBoxYp->Text = "Error!";
				textBoxRa->Text = "Error!";
				textBoxRp->Text = "Error!";
				textBoxTa->Text = "Error!";
				textBoxTp->Text = "Error!";
			}
			else{
				LabelErrorSun->Visible = 0;
				int Dpx = 2 * cvRound(matahari[0][2]);
				textBoxDdet->Text = Dpx + " px";
				float ratio = D / Dpx;
				textBoxRatio->Text = ratio + " arcsec/px";
				float Xp = (cvRound(matahari[0][0]) - frame.cols / 2);
				textBoxXa->Text = (float)(ratio * Xp) + " arcsec";
				textBoxXp->Text = Xp + " px";
				float Yp = (frame.rows / 2 - cvRound(matahari[0][1]));
				textBoxYa->Text = (float)(ratio * Yp) + " arcsec";
				textBoxYp->Text = Yp + " px";
				textBoxRa->Text = sqrtf(ratio*ratio*(Xp*Xp + Yp*Yp)) + " arcsec";
				textBoxRp->Text = sqrtf(Xp*Xp + Yp*Yp) + " px";
				float Tp = atanl(abs(Yp / Xp)) * (180 / M_PI);
				if (Xp >= 0 && Yp >= 0){
					Tp = Tp;
				}
				else if (Xp < 0 && Yp >= 0){
					Tp = 180 - Tp;
				}
				else if (Xp < 0 && Yp < 0){
					Tp = 180 + Tp;
				}
				else if (Xp >= 0 && Yp < 0){
					Tp = 360 - Tp;
				}
				textBoxTa->Text = Tp + " degree";
				textBoxTp->Text = Tp + " degree";
			}
		}
		void FrameReadSq(void){
			if (trackBar1->Value < trackBar1->Maximum){
				capture.read(frame); //membaca frame yang sekarang ditunjuk dan memberikan perintah kepada pointer untuk menunjuk frame selanjutnya
				LabelTime->Text = "Time: " + (TimeSpan::FromMilliseconds(capture.get(CV_CAP_PROP_POS_MSEC)).ToString())->Substring(0, 8);
				LabelFrame->Text = "Frame: " + (int)capture.get(CV_CAP_PROP_POS_FRAMES);
				DrawFrame();
				trackBar1->Value = (int)capture.get(CV_CAP_PROP_POS_FRAMES);
			}
			else{
				timer1->Stop();
				buttonPause->Enabled = 0;
				buttonPlay->Enabled = 1;
			}
		}
	private: System::Void buttonOpen_Click(System::Object^  sender, System::EventArgs^  e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			capture.open(MarshalString(openFileDialog1->FileName));
			pictureBoxCitra->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			timer1->Stop();
			timer1->Interval = 1000.0 / (float)capture.get(CV_CAP_PROP_FPS);
			//timer1->Interval = 200;
			capture.set(CV_CAP_PROP_POS_FRAMES, 0);
			trackBar1->Enabled = 1;
			trackBar1->Maximum = (int)capture.get(CV_CAP_PROP_FRAME_COUNT);
			trackBar1->Value = 0;
			numericUpDownC->Enabled = 1;
			numericUpDownE->Enabled = 1;
			buttonPlay->Enabled = 1;
			buttonPause->Enabled = 0;
			dateTimePicker1->Enabled = 1;
			LabelCodec->Text = "Codec: " + System::Text::Encoding::UTF8->GetString(BitConverter::GetBytes((int)capture.get(CV_CAP_PROP_FOURCC)));
			LabelRes->Text = "Resolution: " + (int)capture.get(CV_CAP_PROP_FRAME_WIDTH) + "x" + (int)capture.get(CV_CAP_PROP_FRAME_HEIGHT);
			LabelFPS->Text = "Frame Rate: " + (float)capture.get(CV_CAP_PROP_FPS);
			FrameReadSq();
			s = sunDistanceKM(dateTimePicker1->Value.DayOfYear);
			textBoxdist->Text = s + " km";
			D = sunApprntDCalc(s);
			textBoxDCalc->Text = D + " arcsec";
		}
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			FrameReadSq();
		}
		catch (...){}
	}

	private: System::Void buttonPlay_Click(System::Object^  sender, System::EventArgs^  e) {
		if (trackBar1->Value >= trackBar1->Maximum){
			trackBar1->Value = 0;
			capture.set(CV_CAP_PROP_POS_FRAMES, 0);
		}
		buttonPause->Enabled = 1;
		buttonPlay->Enabled = 0;
		timer1->Start();
	}
	private: System::Void buttonPause_Click(System::Object^  sender, System::EventArgs^  e) {
		buttonPause->Enabled = 0;
		buttonPlay->Enabled = 1;
		timer1->Stop();
	}
	private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
		capture.set(CV_CAP_PROP_POS_FRAMES, trackBar1->Value);
		FrameReadSq();
	}
	private: System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		double r = sunDistanceKM(dateTimePicker1->Value.DayOfYear);
		textBoxdist->Text = r + " km";
		textBoxDCalc->Text = sunApprntDCalc(r) + " arcsec";
	}
	private: System::Void buttonAbout_Click(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show("SolarEye build May 31, 2017.\n"
			"By Gemeinschaft Team :\n"
			"Muhammad S. Yahya S. (41578), Gofindo Saputra S. (41656), Edy Sutrisno (42532), Novega Ghufron A. (42502).\n"
			"Departemen Teknik Nuklir dan Teknik Fisika\n"
			"Fakultas Teknik - Universitas Gadjah Mada",
			"About", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void numericUpDownE_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		DrawFrame();
	}
	private: System::Void numericUpDownC_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		DrawFrame();
	}
	};
}
