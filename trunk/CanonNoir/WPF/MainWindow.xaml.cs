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
        }

        private void test(object sender, RoutedEventArgs e)
        {
            Window1 w = new Window1();
            w.Show();
        }
        private void init_Jeu()
        {
            Init.Visibility = System.Windows.Visibility.Hidden;
            System.Windows.Thickness t = new Thickness(4, 40, 0, 0);
            Jeu.Margin = t;
            Jeu.Visibility = System.Windows.Visibility.Visible;
        }
        private void button1_Click(object sender, RoutedEventArgs e)
        {
            this.init_Jeu();
            FacadeW.setNbJoueurs(2);
        }
            private void button2_Click(object sender, RoutedEventArgs e)
        {
            this.init_Jeu();
            FacadeW.setNbJoueurs(3);
        }
        private void button3_Click(object sender, RoutedEventArgs e)
        {
            this.init_Jeu();
            FacadeW.setNbJoueurs(4);
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


    }
}
