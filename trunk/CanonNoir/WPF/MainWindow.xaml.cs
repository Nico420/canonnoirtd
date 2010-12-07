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

namespace WPF
{
    /// <summary>
    /// Logique d'interaction pour MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        bool test=true;
        public MainWindow()
        {
            InitializeComponent();
        }

        private void canvas1_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            if (test)
            {
                button3.Content = "17";
                test = false;
            }
            else
            {
                button3.Content = "15";
                test = true;
            }
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            if (test)
            {
                button3.Content = "17";
                test = false;
            }
            else
            {
                button3.Content = "15";
                test = true;
            }
        }
    }
}
