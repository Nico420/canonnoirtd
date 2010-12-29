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

        //Pour le lancer de Dés, c'est un systeme qui permet de faire des pauses.
        DispatcherTimer _popupTimer = new DispatcherTimer(DispatcherPriority.Normal);

        public MainWindow()
        {
            InitializeComponent();
            FacadeW = new WrapperFacade();
        }

        private void test(object sender, RoutedEventArgs e)
        {
            Window1 w = new Window1();
            w.Show();
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
            Jeu.Visibility = System.Windows.Visibility.Visible;
        }
        private void button1_Click(object sender, RoutedEventArgs e)
        {
            this.init_Jeu(2);
        }
            private void button2_Click(object sender, RoutedEventArgs e)
        {
            this.init_Jeu(3);
        }
        private void button3_Click(object sender, RoutedEventArgs e)
        {
            this.init_Jeu(4);
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
            
            double num_case = (y-1) * 11 + x;
            MessageBox.Show("Vous avez cliqué ici : " + Mouse.GetPosition(clickZone) + "\nCase : (" +x+";"+ y + ") " + num_case);

        }

        private void LanceDes_Click(object sender, RoutedEventArgs e)
        {
            textBlock3.Text = FacadeW.getMessage();
            int count = 0;
            _popupTimer.Interval = TimeSpan.FromMilliseconds(100);
            _popupTimer.Tick += delegate
            {
                Random rdm1 = new Random(unchecked((int)DateTime.Now.Ticks));
                int a = rdm1.Next(1, 5);
                des1.Source = new BitmapImage(new Uri("Images/face"+a+".jpg", UriKind.Relative));
                a = rdm1.Next(1, 5);
                des2.Source = new BitmapImage(new Uri("Images/face" + a + ".jpg", UriKind.Relative));
                count++;
                if (count > 10)
                {
                    _popupTimer.Stop();
                    count = 0;
                    //FacadeW.lancerDes();
                    des1.Source = new BitmapImage(new Uri("Images/face" + FacadeW.getDes1() + ".jpg", UriKind.Relative));
                    des2.Source = new BitmapImage(new Uri("Images/face" + FacadeW.getDes2() + ".jpg", UriKind.Relative));
                }
            };
            _popupTimer.Start();

            
        }


    }
}
