#pragma once
#include "WelcomeForm.h"

namespace GUICPPKelxx {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		MyForm(void)
		{
			InitializeComponent();

			// Memindahkan panel ke atas background
			panelLogin->Parent = pictureBoxBackground;
			panelLogin->BringToFront();

			// Mengatur transparansi panel
			panelLogin->BackColor = Color::Transparent;

			panelLogin->Paint +=
				gcnew PaintEventHandler(this, &MyForm::GlassPanel_Paint);

			// Membuat panel rounded
			RoundedPanel(panelLogin, 20);
			RoundedPanel(panelUsername, 12);
			RoundedPanel(panelPassword, 12);
			RoundedButton(btnLogin, 20);

			// Mengatur tampilan komponen
			ApplyStyles();

			// Event hover tombol
			btnLogin->MouseEnter +=
				gcnew EventHandler(
					this, &MyForm::LoginButton_MouseEnter
				);

			btnLogin->MouseLeave +=
				gcnew EventHandler(
					this, &MyForm::LoginButton_MouseLeave
				);

			btnLogin->Click +=
				gcnew EventHandler(this, &MyForm::btnLogin_Click);
		}

		void GlassPanel_Paint(System::Object^ sender, PaintEventArgs^ e)
		{
			Panel^ panel = safe_cast<Panel^>(sender);

			e->Graphics->SmoothingMode =
				System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

			Rectangle rect = panel->ClientRectangle;

			GraphicsPath^ path = gcnew GraphicsPath();

			int radius = 20;
			int diameter = radius * 2;

			path->AddArc(rect.X, rect.Y, diameter, diameter, 180, 90);
			path->AddArc(rect.Right - diameter, rect.Y, diameter, diameter, 270, 90);
			path->AddArc(rect.Right - diameter, rect.Bottom - diameter,
				diameter, diameter, 0, 90);
			path->AddArc(rect.X, rect.Bottom - diameter,
				diameter, diameter, 90, 90);

			path->CloseFigure();

			// Glass background
			SolidBrush^ glassBrush =
				gcnew SolidBrush(Color::FromArgb(110, 255, 255, 255));

			e->Graphics->FillPath(glassBrush, path);

			// Glass border
			Pen^ glassBorder =
				gcnew Pen(Color::FromArgb(150, 255, 255, 255), 1.5f);

			e->Graphics->DrawPath(glassBorder, path);

			delete glassBrush;
			delete glassBorder;
			delete path;
		}

	private:
		void btnLogin_Click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ username = txtUsername->Text->Trim();
			String^ password = txtPassword->Text;

			// Validasi input kosong
			if (String::IsNullOrWhiteSpace(username) ||
				String::IsNullOrEmpty(password))
			{
				MessageBox::Show(
					"Username dan password harus diisi!",
					"Login Gagal",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning
				);

				return;
			}

			// Proses autentikasi
			if (String::Equals(username, "admin") &&
				String::Equals(password, "12345"))
			{
				MessageBox::Show(
					"Login berhasil!",
					"Success",
					MessageBoxButtons::OK,
					MessageBoxIcon::Information
				);

				WelcomeForm^ welcome = gcnew WelcomeForm(username);

				this->Hide();
				welcome->ShowDialog();

				this->Close();
			}
			else
			{
				MessageBox::Show(
					"Username atau password salah!",
					"Login Gagal",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);

				txtPassword->Clear();
				txtPassword->Focus();
			}
		}

	private:
		void RoundedButton(Button^ btn, int radius)
		{
			GraphicsPath^ path = gcnew GraphicsPath();

			int d = radius * 2;
			Rectangle bounds = btn->ClientRectangle;

			path->AddArc(bounds.X, bounds.Y, d, d, 180, 90);
			path->AddArc(bounds.Right - d, bounds.Y, d, d, 270, 90);
			path->AddArc(bounds.Right - d, bounds.Bottom - d, d, d, 0, 90);
			path->AddArc(bounds.X, bounds.Bottom - d, d, d, 90, 90);

			path->CloseFigure();

			btn->Region = gcnew System::Drawing::Region(path);

			delete path;
		}

	private:
		void RoundedPanel(Panel^ panel, int radius)
		{
			GraphicsPath^ path = gcnew GraphicsPath();

			int diameter = radius * 2;
			Rectangle bounds = panel->ClientRectangle;

			path->AddArc(
				bounds.X, bounds.Y,
				diameter, diameter, 180, 90
			);

			path->AddArc(
				bounds.Right - diameter, bounds.Y,
				diameter, diameter, 270, 90
			);

			path->AddArc(
				bounds.Right - diameter,
				bounds.Bottom - diameter,
				diameter, diameter, 0, 90
			);

			path->AddArc(
				bounds.X, bounds.Bottom - diameter,
				diameter, diameter, 90, 90
			);

			path->CloseFigure();

			panel->Region = gcnew System::Drawing::Region(path);

			delete path;
		}


	private:
		void ApplyStyles()
		{
			// Judul Login
			lblTitle->ForeColor = Color::Black;
			lblTitle->Font = gcnew System::Drawing::Font(
				"Segoe UI", 22.0f,
				System::Drawing::FontStyle::Bold
			);
			lblTitle->BackColor = Color::Transparent;
			lblTitle->Text = "Login";

			panelUsername->BackColor = Color::White;

			// Panel Password
			panelPassword->BackColor = Color::White;

			// Username
			txtUsername->Font = gcnew System::Drawing::Font(
				"Segoe UI", 10.0f
			);

			txtUsername->BackColor = Color::White;
			txtUsername->ForeColor = Color::FromArgb(
				45, 20, 75
			);
			txtUsername->BorderStyle = BorderStyle::None;

			// Password
			txtPassword->Font = gcnew System::Drawing::Font(
				"Segoe UI", 10.0f
			);

			txtPassword->BackColor = Color::White;
			txtPassword->ForeColor = Color::FromArgb(
				45, 20, 75
			);
			txtPassword->BorderStyle = BorderStyle::None;

			txtPassword->UseSystemPasswordChar = true;

			// Remember Me
			chkRemember->Text = "Remember Me";
			chkRemember->ForeColor = Color::White;
			chkRemember->BackColor = Color::Transparent;

			// Button Login
			btnLogin->Text = "Login";
			btnLogin->BackColor = Color::White;
			btnLogin->ForeColor = Color::FromArgb(
				55, 20, 90
			);

			btnLogin->FlatStyle = FlatStyle::Flat;
			btnLogin->FlatAppearance->BorderSize = 0;

			btnLogin->Font = gcnew System::Drawing::Font(
				"Segoe UI", 10.0f,
				System::Drawing::FontStyle::Bold
			);

			btnLogin->FlatAppearance->MouseOverBackColor =
				Color::FromArgb(190, 150, 255);

			btnLogin->FlatAppearance->MouseDownBackColor =
				Color::FromArgb(150, 110, 220);

			btnLogin->Cursor = Cursors::Hand;
		}


	private:
		void LoginButton_MouseEnter(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			btnLogin->BackColor =
				Color::FromArgb(190, 150, 255);
		}

		void LoginButton_MouseLeave(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			btnLogin->BackColor = Color::White;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBoxBackground;
	protected:
	private: System::Windows::Forms::Panel^ panelLogin;
private: System::Windows::Forms::Label^ lblTitle;

	private: System::Windows::Forms::Button^ btnLogin;
	private: System::Windows::Forms::CheckBox^ chkRemember;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::TextBox^ txtUsername;
private: System::Windows::Forms::Panel^ panelUsername;
private: System::Windows::Forms::Panel^ panelPassword;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBoxBackground = (gcnew System::Windows::Forms::PictureBox());
			this->panelLogin = (gcnew System::Windows::Forms::Panel());
			this->panelPassword = (gcnew System::Windows::Forms::Panel());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->panelUsername = (gcnew System::Windows::Forms::Panel());
			this->txtUsername = (gcnew System::Windows::Forms::TextBox());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->chkRemember = (gcnew System::Windows::Forms::CheckBox());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxBackground))->BeginInit();
			this->panelLogin->SuspendLayout();
			this->panelPassword->SuspendLayout();
			this->panelUsername->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBoxBackground
			// 
			this->pictureBoxBackground->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBoxBackground->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxBackground.Image")));
			this->pictureBoxBackground->Location = System::Drawing::Point(0, 0);
			this->pictureBoxBackground->Name = L"pictureBoxBackground";
			this->pictureBoxBackground->Size = System::Drawing::Size(1000, 650);
			this->pictureBoxBackground->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxBackground->TabIndex = 0;
			this->pictureBoxBackground->TabStop = false;
			// 
			// panelLogin
			// 
			this->panelLogin->BackColor = System::Drawing::Color::LightGray;
			this->panelLogin->Controls->Add(this->panelPassword);
			this->panelLogin->Controls->Add(this->panelUsername);
			this->panelLogin->Controls->Add(this->btnLogin);
			this->panelLogin->Controls->Add(this->chkRemember);
			this->panelLogin->Controls->Add(this->lblTitle);
			this->panelLogin->Location = System::Drawing::Point(313, 129);
			this->panelLogin->Name = L"panelLogin";
			this->panelLogin->Size = System::Drawing::Size(360, 420);
			this->panelLogin->TabIndex = 1;
			// 
			// panelPassword
			// 
			this->panelPassword->BackColor = System::Drawing::Color::White;
			this->panelPassword->Controls->Add(this->txtPassword);
			this->panelPassword->Location = System::Drawing::Point(44, 139);
			this->panelPassword->Name = L"panelPassword";
			this->panelPassword->Size = System::Drawing::Size(290, 42);
			this->panelPassword->TabIndex = 6;
			// 
			// txtPassword
			// 
			this->txtPassword->BackColor = System::Drawing::Color::White;
			this->txtPassword->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPassword->Location = System::Drawing::Point(10, 10);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(270, 23);
			this->txtPassword->TabIndex = 2;
			// 
			// panelUsername
			// 
			this->panelUsername->BackColor = System::Drawing::Color::White;
			this->panelUsername->Controls->Add(this->txtUsername);
			this->panelUsername->Location = System::Drawing::Point(44, 70);
			this->panelUsername->Name = L"panelUsername";
			this->panelUsername->Size = System::Drawing::Size(290, 42);
			this->panelUsername->TabIndex = 5;
			this->panelUsername->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// txtUsername
			// 
			this->txtUsername->BackColor = System::Drawing::Color::White;
			this->txtUsername->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtUsername->Location = System::Drawing::Point(10, 10);
			this->txtUsername->Name = L"txtUsername";
			this->txtUsername->Size = System::Drawing::Size(270, 23);
			this->txtUsername->TabIndex = 1;
			this->txtUsername->TextChanged += gcnew System::EventHandler(this, &MyForm::txtUsername_TextChanged);
			// 
			// btnLogin
			// 
			this->btnLogin->BackColor = System::Drawing::Color::White;
			this->btnLogin->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLogin->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->btnLogin->Location = System::Drawing::Point(44, 230);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(290, 45);
			this->btnLogin->TabIndex = 4;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = false;
			// 
			// chkRemember
			// 
			this->chkRemember->Location = System::Drawing::Point(44, 196);
			this->chkRemember->Name = L"chkRemember";
			this->chkRemember->Size = System::Drawing::Size(109, 19);
			this->chkRemember->TabIndex = 3;
			this->chkRemember->Text = L"Remember me";
			this->chkRemember->UseVisualStyleBackColor = true;
			this->chkRemember->CheckedChanged += gcnew System::EventHandler(this, &MyForm::chkRemember_CheckedChanged);
			// 
			// lblTitle
			// 
			this->lblTitle->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitle->Location = System::Drawing::Point(131, 26);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(52, 23);
			this->lblTitle->TabIndex = 0;
			this->lblTitle->Text = L"Login";
			this->lblTitle->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1000, 650);
			this->Controls->Add(this->panelLogin);
			this->Controls->Add(this->pictureBoxBackground);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxBackground))->EndInit();
			this->panelLogin->ResumeLayout(false);
			this->panelLogin->PerformLayout();
			this->panelPassword->ResumeLayout(false);
			this->panelPassword->PerformLayout();
			this->panelUsername->ResumeLayout(false);
			this->panelUsername->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
private: System::Void txtUsername_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void chkRemember_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
