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
        IntPtr traj,histo;
        int angle_int,puiss_int;
        double largeur_totale;
        int[] entiers = new int[200];

        public Window1()
        {
            InitializeComponent();
        }

        public Window1(MainWindow m)
        {
            this.m = m;
            angle_int = 0;
            largeur_totale = 0;
            InitializeComponent();
            textChoixAngle.Text=m.FacadeW.getMessage();
            displayRelief();
        }
        public Window1(MainWindow m,IntPtr a,IntPtr b)
        {
            this.m = m;
            this.traj = a;
            this.histo = b;
            angle_int = 0;
            puiss_int = 0;
            InitializeComponent();
            textChoixAngle.Text = m.FacadeW.getMessage();
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
            int l1 = 0;
            int l2 = 0;
            double[] liste_hauteur = new double[38];
            double[] liste_largeur = new double[38];
            for (int i = 0; i < 36; i+=2)
            {
                int largeur = Marshal.ReadInt32(histo);
                liste_largeur[l1++] = (((double)largeur) / 1000);
                largeur_totale += (((double)largeur) / 1000);
                histo += sizeof(int);
                int hauteur = Marshal.ReadInt32(histo);
                liste_hauteur[l2++] = (((double)hauteur) / 1000);
                histo += sizeof(int);
            }
            distance.Text = "Distance : " + largeur_totale + " milles nautique";
            //We make the scale thanks to largeur_totale
            double largeur_float = 0;

            for (int i = 0; i < 36; i++)
            {
                Rectangle myRect = new System.Windows.Shapes.Rectangle();
                myRect.Stroke = System.Windows.Media.Brushes.Black;
                myRect.Fill = System.Windows.Media.Brushes.Black;
                myRect.RadiusX = 2;
                myRect.RadiusY = 2;
                myRect.StrokeThickness = 7;
                myRect.HorizontalAlignment = HorizontalAlignment.Left;
                myRect.VerticalAlignment = VerticalAlignment.Center;
                myRect.Height = liste_hauteur[i]*100;
                myRect.Width = liste_largeur[i]*1000;
                myRect.Margin = new Thickness(largeur_float, zoneTir.Height-myRect.Height, 0, 0);
                largeur_float += liste_largeur[i]*1000;
                //MessageBox.Show(largeur_float + ""+liste_hauteur[i]);
                zoneTir.Children.Add(myRect);
                
            }
        }
        private void displayTraj()
        {
            int xi = Marshal.ReadInt32(traj);
            traj += sizeof(int);
            int yi = Marshal.ReadInt32(traj);
            traj += sizeof(int);
            xi = Marshal.ReadInt32(traj);
            traj += sizeof(int);
            yi = Marshal.ReadInt32(traj);
            traj += sizeof(int);
            for (int i = 0;i < 100; i++)
            {
                xi = Marshal.ReadInt32(traj);
                traj += sizeof(int);
                yi = Marshal.ReadInt32(traj);
                traj += sizeof(int);
                double x = (double)xi / 100;
                double y = (double)yi / 100;
                //MessageBox.Show("displayTraj " + x + " " + y);
                Image boulet = new Image();
                BitmapImage boulet_img = new BitmapImage(new Uri("Images/boulet.jpg", UriKind.Relative));
                boulet.Source = boulet_img;
                boulet.Height = 10;
                boulet.Width = 10;
                boulet.HorizontalAlignment = HorizontalAlignment.Left;
                boulet.VerticalAlignment = VerticalAlignment.Center;
                zoneTir.Children.Add(boulet);
                //Il faut encore synchroniser l'affichage avec la largeur !
                System.Windows.Thickness t = new Thickness(puiss_int*x, 500, 0, 0);
                boulet.Margin = t;
                
            }
        }
        private void choixPuissance(object sender, RoutedEventArgs e)
        {
            
            double puiss = (puiss_image.ActualHeight - Mouse.GetPosition(puiss_image).Y) / puiss_image.ActualHeight;
            int puissance_int = (int) Math.Round(puiss*100);
            valeurPuiss.Text =  "Puissance : " + puissance_int +"mètres/s";
            puissance.Visibility = System.Windows.Visibility.Hidden;
            m.FacadeW.setPuissance(puissance_int);
            this.puiss_int = puissance_int;
	        //Display the shoot's way !
            //displayTraj();
            

            MessageBox.Show("Fin du tir !");
            this.Close();
        }
    }
}

