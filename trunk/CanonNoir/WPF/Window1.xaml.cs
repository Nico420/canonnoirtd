using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using Wrapper;
using System.Runtime.InteropServices;
using System.Windows.Threading;


namespace WPF
{
    /// <summary>
    /// Logique d'interaction pour Window1.xaml
    /// </summary>
    public partial class Window1 : Window
    {
        //Thanks to this attribut, we can access to Facade in an easy way ! m.FacadeW
        MainWindow m;
        int angle_int;
        public Window1()
        {
            InitializeComponent();
        }

        public Window1(MainWindow m)
        {
            this.m = m;
            MessageBox.Show(m.FacadeW.getScores().GetHashCode()+"");
            angle_int = 0;
            InitializeComponent();
            textChoixAngle.Text=m.FacadeW.getMessage();
            displayRelief();
        }
        
        private void finCombat(object sender, RoutedEventArgs e)
        {
            
            this.Close();
        }

        private void choixAngle(object sender, RoutedEventArgs e)
        {
            double a = Mouse.GetPosition(angle).X / angle.ActualWidth;
            double b = (angle.ActualHeight - Mouse.GetPosition(angle).Y) / angle.ActualHeight;
            double r = Math.Sqrt(a*a + b*b);
            double t = Math.Acos(a/r);
            t =(int) 180*t/Math.PI;
            int theta = (int) Math.Round(t);
            valeurAngle.Text = "Angle : " + theta + "°";
            stackPanel1.Visibility = System.Windows.Visibility.Hidden;
            System.Windows.Thickness z = stackPanel1.Margin;
            puissance.Margin = z;
            puissance.Visibility = System.Windows.Visibility.Visible;
            m.FacadeW.setAngle(theta);
            this.angle_int = theta;
            textChoixPuiss.Text = m.FacadeW.getMessage();
        }

        /// <summary>
        /// Thank to this method, we can show the montains for the shot !
        /// </summary>
        private void displayRelief()
        {
            IntPtr a = new IntPtr(m.FacadeW.getHisto().GetHashCode());
            a += sizeof(int);
            a += sizeof(int);
            a += sizeof(int);
            a += sizeof(int);
            a += sizeof(int);
            a += sizeof(int);
            a += sizeof(int);
            a += sizeof(int);
            int largeur = Marshal.ReadInt32(a);
            a+=sizeof(int);
            int hauteur = Marshal.ReadInt32(a);
            a += sizeof(int);
            MessageBox.Show(largeur + " " + hauteur);
            while (largeur > 0)
            {
                MessageBox.Show(largeur + " " + hauteur);
            }
        }
        private void displayTraj()
        {
            IntPtr a = new IntPtr(m.FacadeW.getTrajectoire().GetHashCode());
            int x = Marshal.ReadInt32(a);
            a += sizeof(int);
            int y = Marshal.ReadInt32(a);
            a += sizeof(int);
            for (int i = 0; i < 100; i++)
            {
                x = Marshal.ReadInt32(a);
                a += sizeof(int);
                y = Marshal.ReadInt32(a);
                a += sizeof(int);
                Image boulet = new Image();
                BitmapImage boulet_img = new BitmapImage(new Uri("Images/boulet.jpg", UriKind.Relative));
                boulet.Source = boulet_img;
                boulet.Height = 10;
                boulet.Width = 10;
                boulet.HorizontalAlignment = HorizontalAlignment.Left;
                boulet.VerticalAlignment = VerticalAlignment.Center;
                zoneTir.Children.Add(boulet);
                System.Windows.Thickness t = new Thickness(x, y, 0, 0);
                boulet.Margin = t;
                MessageBox.Show(x + " " + y);
            }
        }
        private void choixPuissance(object sender, RoutedEventArgs e)
        {
            
            double puiss = (puiss_image.ActualHeight - Mouse.GetPosition(puiss_image).Y) / puiss_image.ActualHeight;
            int puissance_int = (int) Math.Round(puiss*100);
            valeurPuiss.Text =  "Puissance : " + puissance_int +"mètres/s";
            puissance.Visibility = System.Windows.Visibility.Hidden;
            m.FacadeW.setPuissance(puissance_int);
            double pi=3.1415;
	        double angle_rad = 2*pi*angle_int/360;
	        //Display the shoot's way !
            displayTraj();
            

            MessageBox.Show("Touché !");
            this.Close();
        }
    }
}

