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
using System.Windows.Navigation;
using System.Windows.Shapes;
using Wrapper;
using System.Runtime.InteropServices;
using System.Windows.Threading;

namespace WPF
{
    /// <summary>
    /// Logique d'interaction pour MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        WrapperFacade FacadeW;
        //1/11 de clickZone
        private static double HAUTEUR_CASE = 53.75;

        // 1/8 de clickZone
        private static double LARGEUR_CASE = 60.454545;

        public MainWindow()
        {
            InitializeComponent();
            FacadeW = new WrapperFacade();
            LanceDes.IsEnabled = false;
        }

        private void test(object sender, RoutedEventArgs e)
        {
            Window1 w = new Window1();
            w.Show();
        }

        private void setCases()
        {
            IntPtr a = new IntPtr(FacadeW.getCasesActives().GetHashCode());
            int b;
            for(int i =0;i< 88;i++){
                b = Marshal.ReadInt32(a);
                a+=sizeof (int);
                if (b == 1)
                {
                    MessageBox.Show("FacadeW.getCasesActives() " + b);
                    
                    Rectangle myRect = new System.Windows.Shapes.Rectangle();
                    myRect.Stroke = System.Windows.Media.Brushes.Black;
                    //myRect.Fill = System.Windows.Media.Brushes.SkyBlue;
                    myRect.HorizontalAlignment = HorizontalAlignment.Left;
                    myRect.VerticalAlignment = VerticalAlignment.Center;
                    myRect.Height = HAUTEUR_CASE;
                    myRect.Width = LARGEUR_CASE;
                    int x = (i / 11);
                    int y = i - x*11;
                    MessageBox.Show("Coordonnée " + x+" " +y);
                    myRect.Margin = new Thickness((y) * HAUTEUR_CASE,(x) * LARGEUR_CASE, 0, 0);

                    clickZone.Children.Add(myRect);
                }
            }
        }
        private void init_Jeu(int a)
        {
            Init.Visibility = System.Windows.Visibility.Hidden;
            /*System.Windows.Thickness t = new Thickness(0, -40, 0, 0);
            Jeu.Margin = t;*/
            switch (a)
            {
                case 2:
                    joueur3.Visibility = System.Windows.Visibility.Hidden;
                    joueur4.Visibility = System.Windows.Visibility.Hidden;
                    break;
                case 3:
                    joueur4.Visibility = System.Windows.Visibility.Hidden;
                    break;
                default:
                break;
            };
            FacadeW.setNbJoueurs(a);
            this.setCases();
            textBlock3.Text = FacadeW.getMessage() + " <- Message du moteur";
            Jeu.Visibility = System.Windows.Visibility.Visible;
        }
        private void button1_Click(object sender, RoutedEventArgs e)
        {
            this.init_Jeu(2);
        }
            private void button2_Click(object sender, RoutedEventArgs e)
        {
            this.init_Jeu(4);
        }
        private void button3_Click(object sender, RoutedEventArgs e)
        {
            this.init_Jeu(3);
        }
        
        private void fullscreen(object sender, RoutedEventArgs e)
        {
            this.WindowState= System.Windows.WindowState.Maximized;
        }

        private void clickZone_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            double a = Mouse.GetPosition(clickZone).X;
            a/= LARGEUR_CASE;
            int x = (int)a+1;
            double b = Mouse.GetPosition(clickZone).Y;
            b /= HAUTEUR_CASE; 
            int y = (int)b + 1;
            FacadeW.setClick(x,y);
            if (FacadeW.activerDes())
            {
                this.LanceDes.IsEnabled = true;
            }
            textBlock3.Text = FacadeW.getMessage() + " <- Message du moteur";
            double num_case = (y-1) * 11 + x;
            MessageBox.Show("Vous avez cliqué ici : " + Mouse.GetPosition(clickZone) + "\nCase : (" +x+";"+ y + ") " + num_case);
        }

        private void LanceDes_Click(object sender, RoutedEventArgs e)
        {
            //LanceDes.IsEnabled = false;
            int count = 0;
            //Pour le lancer de Dés, c'est un systeme qui permet de faire des pauses.
            DispatcherTimer _lancerDesTimer = new DispatcherTimer(DispatcherPriority.Normal);
            _lancerDesTimer.Interval = TimeSpan.FromMilliseconds(100);
            _lancerDesTimer.Tick += delegate
            {
                Random rdm1 = new Random(unchecked((int)DateTime.Now.Ticks));
                int a = rdm1.Next(1, 6);
                des1.Source = new BitmapImage(new Uri("Images/face"+a+".jpg", UriKind.Relative));
                a = rdm1.Next(1, 6);
                des2.Source = new BitmapImage(new Uri("Images/face" + a + ".jpg", UriKind.Relative));
                count++;
                if (count > 10)
                {
                    _lancerDesTimer.Stop();
                    count = 0;
                    FacadeW.lancerDes();
                    textBlock3.Text = FacadeW.getMessage() + " <- Message du moteur";
                    des1.Source = new BitmapImage(new Uri("Images/face" + FacadeW.getDes1() + ".jpg", UriKind.Relative));
                    des2.Source = new BitmapImage(new Uri("Images/face" + FacadeW.getDes2() + ".jpg", UriKind.Relative));
                    MessageBox.Show(FacadeW.getDes1() + " " + FacadeW.getDes2());
                }
            };
            _lancerDesTimer.Start();
            
        }


    }
}
