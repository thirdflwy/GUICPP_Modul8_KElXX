#pragma once

namespace GUICPPKelxx {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for WelcomeForm
	/// </summary>
	public ref class WelcomeForm : public System::Windows::Forms::Form
	{
	public:
		WelcomeForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			SetupWelcomeLabel();
			btnExit->Click +=
				gcnew EventHandler(this, &WelcomeForm::btnExit_Click);
		}

		WelcomeForm(String^ username)
		{
			InitializeComponent();

			lblWelcome->Text =
				"Selamat Datang, Praktikan Progdas";

			btnExit->Click +=
				gcnew EventHandler(this, &WelcomeForm::btnExit_Click);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~WelcomeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBoxWelcome;
	private: System::Windows::Forms::Button^ btnExit;
	private: System::Windows::Forms::Label^ lblWelcome;

	private:
		void SetupWelcomeLabel()
		{
			lblWelcome->Parent = pictureBoxWelcome;
			lblWelcome->BringToFront();

			lblWelcome->Dock = DockStyle::Fill;
			lblWelcome->AutoSize = false;

			lblWelcome->BackColor = Color::Transparent;
			lblWelcome->ForeColor = Color::White;

			lblWelcome->TextAlign = ContentAlignment::MiddleCenter;
			lblWelcome->BorderStyle = BorderStyle::None;
		}

	private:
		void btnExit_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Application::Exit();
		}

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(WelcomeForm::typeid));
			this->pictureBoxWelcome = (gcnew System::Windows::Forms::PictureBox());
			this->lblWelcome = (gcnew System::Windows::Forms::Label());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxWelcome))->BeginInit();
			this->pictureBoxWelcome->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBoxWelcome
			// 
			this->pictureBoxWelcome->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBoxWelcome->Controls->Add(this->lblWelcome);
			this->pictureBoxWelcome->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBoxWelcome->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxWelcome.Image")));
			this->pictureBoxWelcome->Location = System::Drawing::Point(0, 0);
			this->pictureBoxWelcome->Name = L"pictureBoxWelcome";
			this->pictureBoxWelcome->Size = System::Drawing::Size(1000, 650);
			this->pictureBoxWelcome->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxWelcome->TabIndex = 0;
			this->pictureBoxWelcome->TabStop = false;
			// 
			// lblWelcome
			// 
			this->lblWelcome->BackColor = System::Drawing::Color::Transparent;
			this->lblWelcome->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblWelcome->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblWelcome->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->lblWelcome->Location = System::Drawing::Point(0, 0);
			this->lblWelcome->Name = L"lblWelcome";
			this->lblWelcome->Size = System::Drawing::Size(1000, 202);
			this->lblWelcome->TabIndex = 1;
			this->lblWelcome->Text = L"Selamat Datang! Praktikan Progdas";
			this->lblWelcome->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblWelcome->Click += gcnew System::EventHandler(this, &WelcomeForm::lblWelcome_Click_1);
			// 
			// btnExit
			// 
			this->btnExit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->btnExit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnExit->ForeColor = System::Drawing::Color::White;
			this->btnExit->Location = System::Drawing::Point(440, 480);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(120, 45);
			this->btnExit->TabIndex = 1;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = false;
			// 
			// WelcomeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1000, 650);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->pictureBoxWelcome);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"WelcomeForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Welcome Page";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxWelcome))->EndInit();
			this->pictureBoxWelcome->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void lblWelcome_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void lblWelcome_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
