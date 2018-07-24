using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;

using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net.Mail;
using System.Net;




namespace StudentManagementSystem
{
    public partial class Home : Form
    {
        public Home()
        {
            InitializeComponent();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void Login_Click(object sender, EventArgs e)
        {
            string username = UsernameTextBox.Text;
            string password = PasswordtextBox.Text;

            SqlConnection connection = new SqlConnection("Data Source=DESKTOP-IK7L260\\SQLEXPRESS;Initial Catalog=StudentDB; Integrated Security=true");
            connection.Open();

            SqlCommand selectCommand = new SqlCommand(" select * from tbl_registration where username = '" + username + "' and password ='" + password + "'" , connection );



            SqlDataReader dataFromDb =  selectCommand.ExecuteReader();
            if (dataFromDb.HasRows)
            {


                this.Hide();
                Feature featureFrom = new Feature();
                featureFrom.Show();

            }
            else {
                MessageBox.Show("Invalid Data");
            }


        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(RegistrationGroupBox.Visible== true )
            RegistrationGroupBox.Visible = false;
            else
            RegistrationGroupBox.Visible = true;



        }

        private void label4_Click(object sender, EventArgs e)
        {

        }
  
        private void RegistrationGroupBox_Enter(object sender, EventArgs e)
        {

        }

        private void SubmitBtn_Click(object sender, EventArgs e)
        {


            string name = UsertextBox.Text;
            string email=  GmailtextBox.Text;
            string password= PasstextBox.Text;
            string confirmpassword = ConfirmpasstextBox.Text;

            Console.WriteLine(name + email + password + confirmpassword);




            //----------emailVerification
            if (!email.Contains("@") && !email.Contains(".com"))
            {

                GmailLable.ForeColor = Color.Red;
            }
            else
            {
                GmailLable.ForeColor = Color.Blue;
            }
            //----------UserNameVerification
            if (!System.Text.RegularExpressions.Regex.IsMatch(UsertextBox.Text, "[A-Z]"))
            {
                UsernameLable.ForeColor = Color.Red;
                MessageBox.Show("Please Use Both UpperCase and LowerCase");


            }
            else if (!System.Text.RegularExpressions.Regex.IsMatch(UsertextBox.Text, "[a-z]"))
            {
                UsernameLable.ForeColor = Color.Red;
                MessageBox.Show("Please Use Both UpperCase and LowerCase");

            }
            else
            {
                UsernameLable.ForeColor = Color.Blue;
            }
            //----------PasswordVerification
            if (!System.Text.RegularExpressions.Regex.IsMatch(password, @"[^a-zA-Z0-9]") && password != confirmpassword)
            {
                MessageBox.Show("Please Use  numbers,letters and special character and same password at both term ");
                PasswordLable.ForeColor = Color.Red;
                ConfirmPasswordLable.ForeColor = Color.Red;


            }
            else if (!System.Text.RegularExpressions.Regex.IsMatch(password, @"[^a-zA-Z0-9]") && password == confirmpassword) {
                MessageBox.Show("Please Use  numbers,letters and special character and same password at both term ");
                PasswordLable.ForeColor = Color.Red;
                ConfirmPasswordLable.ForeColor = Color.Red;

            }
            else

            {
                PasswordLable.ForeColor = Color.Blue;
                ConfirmPasswordLable.ForeColor = Color.Blue;
            }
            //----------DatabaseEntryVerification&Connection&ConfirmationMail
            if (System.Text.RegularExpressions.Regex.IsMatch(password, @"[^a-zA-Z0-9]") && password == confirmpassword && email.Contains("@") && email.Contains(".com") && name != null && System.Text.RegularExpressions.Regex.IsMatch(UsertextBox.Text, "[A-Z]") && System.Text.RegularExpressions.Regex.IsMatch(UsertextBox.Text, "[a-z]"))
            {
                SqlConnection connection = new SqlConnection("Data Source=DESKTOP-IK7L260\\SQLEXPRESS;Initial Catalog=StudentDB; Integrated Security=true");
                connection.Open();

                SqlCommand insertCommand = new SqlCommand(" insert into registration(user_id,country,institution,email,password) values ('"+name+"','"+email+"','"+password+"') ", connection);

                insertCommand.ExecuteNonQuery();

                MailMessage mail = new MailMessage();
                SmtpClient SmtpServer = new SmtpClient("smtp.gmail.com");

                mail.From = new MailAddress("jamilhossainsujon@gmail.com");
                mail.To.Add(email);
                mail.Subject = "Confirmation Mail";
                mail.Body = "Your registration is succesfull !!!!!!!!!";

                SmtpServer.Port = 587;
                SmtpServer.Credentials = new System.Net.NetworkCredential("jamilhossainsujon", "Give Password Here");
                SmtpServer.EnableSsl = true;

                SmtpServer.Send(mail);
                MessageBox.Show("Registration Successfull!");


            }

            else
            {
                MessageBox.Show("Follow Proper Instruction");
            }



        }

        private void UsertextBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void Home_Load(object sender, EventArgs e)
        {

        }
    }
}
