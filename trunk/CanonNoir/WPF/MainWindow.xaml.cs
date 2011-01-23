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
    /// Interactions for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public WrapperFacade FacadeW;
        //1/11 of the click area. For the moment it's a constant, but we can perhaps make it dynamic.
        private static double HAUTEUR_CASE = 53.75;

        // 1/8 of the click area. For the moment it's a constant, but we can perhaps make it dynamic.
        private static double LARGEUR_CASE = 60.454545;

        private const int ROUGE = 1;
        private const int BLEU = 4;
        private const int VERT = 3;
        private const int JAUNE = 2;
        // Those variables are usefull in order to "clean" the map (we mean erase the rectangle that we draw).
        private int nbCasesRect = 0;
        private int dernierIndex = 0;
        private int nbCasesChoix = 0;
        private int dernierIndexPort = 0;
        private int nbBateaux = 0;
        private int dernierIndexBateau = 0;
        /// <summary>
        /// Method for creation of a new main Window. We need to associated a Facade to this Windows.
        /// At the beginning, we can not roll the dice, so we disabled it.
        /// </summary>
        public MainWindow()
        {
            InitializeComponent();
            //Creation of a Facade, thanks to the Wrapper.
            FacadeW = new WrapperFacade();
            LanceDes.IsEnabled = false;
        }

        /// <summary>
        /// Method that create a new frame for the shoot between boats.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void tirCanon(object sender, RoutedEventArgs e)
        {
            Window1 w = new Window1();
            w.Show();
            double a = Mouse.GetPosition(clickZone).X / clickZone.ActualWidth;
            double b = (clickZone.ActualHeight - Mouse.GetPosition(clickZone).Y) / clickZone.ActualHeight;
        }

        
        private void updateScore()
        {
            scorebox.Visibility = System.Windows.Visibility.Visible;
            IntPtr score = new IntPtr(FacadeW.getScores().GetHashCode());
            System.Windows.Thickness t = new Thickness(0, 0, 0, 0);
            
            int scorebleu = 0, scorerouge = 0, scorejaune = 0, scorevert = 0;
                scorerouge = Marshal.ReadInt32(score);
                score += sizeof(int);
                scorejaune += Marshal.ReadInt32(score);
                score += sizeof(int);
                scorevert = Marshal.ReadInt32(score);
                score += sizeof(int);
                scorebleu += Marshal.ReadInt32(score);
                //MessageBox.Show("" + score + " " + scorerouge + " " + scorejaune + " " + scorevert + " " + scorebleu);
                if (scorerouge >= 0)
                {
                    joueurRouge.Text = "Bateau Rouge : " + scorerouge;
                    joueurRouge.Margin = t;
                    t.Top += 20;
                    joueurRouge.Visibility = System.Windows.Visibility.Visible;
                }
                if (scorejaune >= 0)
                {
                    joueurJaune.Text = "Bateau Jaune : " + scorejaune;
                    joueurJaune.Margin = t;
                    t.Top += 20;
                    joueurJaune.Visibility = System.Windows.Visibility.Visible;
                }
                if (scorevert >= 0)
                {
                    joueurVert.Text = "Bateau Vert : " + scorevert;
                    joueurVert.Margin = t;
                    t.Top += 20;
                    joueurVert.Visibility = System.Windows.Visibility.Visible;
                }
                if (scorebleu >= 0)
                {
                    joueurBleu.Text = "Bateau Bleu : " + scorebleu;
                    joueurBleu.Margin = t;
                    t.Top += 20;
                    joueurBleu.Visibility = System.Windows.Visibility.Visible;
                }
        }

        /// <summary>
        /// This function is used to set a boat at a given position.
        /// </summary>
        /// <param name="x">boat's x</param>
        /// <param name="y">boat's y</param>
        /// <param name="type">Give the type of boat : 0 for Caravelle, 1 for Frégate, 2 for Radeau</param>
        /// <param name="tresor">true if a tresor is on the boat, else false.</param>
        private void afficherBateau(int x, int y, int type, bool tresor,int couleur)
        {
            String bateau = "bateau-";
            switch (type)
            {
                case 3:
                    bateau += "Caravelle";
                    break;
                case 2:
                    bateau += "fregate";
                    break;
                case 1:
                    bateau += "radeau";
                    break;

            }

            
            switch (couleur) 
            {
                case BLEU:
                    bateau += "_bleu";
                    break;
                case ROUGE:
                    bateau+="_rouge";
                    break;
                case VERT:
                    bateau += "_vert";
                    break;
                case JAUNE:
                    bateau += "_jaune";
                    break;
                default:
                    break;
            }
            if (tresor) bateau += "-tresor";
            bateau += ".bmp";
            Button bat = new Button();
            bat.Height = HAUTEUR_CASE - 5;
            bat.Width = LARGEUR_CASE - 10;
            bat.Margin = new Thickness(x * LARGEUR_CASE + clickZone.Margin.Left + 7, y * HAUTEUR_CASE + clickZone.Margin.Top + 5, 0, 0);
            bat.AddHandler(Button.ClickEvent, new RoutedEventHandler(Attaque));
            Image image = new Image();
            BitmapImage bateau_img = new BitmapImage(new Uri("Images/" + bateau, UriKind.Relative));
            image.Source = bateau_img;
            image.Height = HAUTEUR_CASE - 5;
            image.Width = LARGEUR_CASE -5 ;
            image.HorizontalAlignment = HorizontalAlignment.Left;
            image.VerticalAlignment = VerticalAlignment.Center;
            //image.Margin = new Thickness(x * LARGEUR_CASE + clickZone.Margin.Left+7, y * HAUTEUR_CASE + clickZone.Margin.Top+5, 0, 0);
            nbBateaux++;
            bat.Content = image;
            plateau.Children.Add(bat);
            dernierIndexBateau = plateau.Children.IndexOf(bat);
        }

        void Attaque(object sender, RoutedEventArgs e)
        {
            if (FacadeW.afficheCanon())
            {
                double a = Mouse.GetPosition(clickZone).X;
                a /= LARGEUR_CASE;
                int x = (int)a + 1;
                double b = Mouse.GetPosition(clickZone).Y;
                b /= HAUTEUR_CASE;
                int y = (int)b + 1;
                //FacadeW.setClick(x, y);
                MessageBox.Show("" + x + " " + y);
            }
            Window1 w = new Window1(this);
            w.Show();
        }



        /// <summary>
        /// Method that create Rectangle around boxes of the map.
        /// </summary>
        private void setCases()
        {
            int d = dernierIndexPort - nbCasesRect;
            int e = dernierIndex - nbCasesChoix;
            plateau.Children.RemoveRange(d+1, nbCasesRect);
            clickZone.Children.RemoveRange(e+1, nbCasesChoix);
            nbCasesRect =0;
            nbCasesChoix =0;
            if (FacadeW.activerCases())
            {
                //This pointer is create to get the table of active boxes from the Facade.
                IntPtr a = new IntPtr(FacadeW.getCasesActives().GetHashCode());
                /*Display enable case*/
                for (int i = 0; i < 88; i++)
                {
                    //This integer is create by reading the content associate to the pointer.
                    int b = Marshal.ReadInt32(a);
                    // We "incremente" a from the size of an int, to get the next int from the table.
                    a += sizeof(int);
                    //
                    //Display the available ports
                    //
                    if (b == 1 && FacadeW.affichePorts())
                    {
                        Rectangle myRect = new System.Windows.Shapes.Rectangle();
                        myRect.Stroke = System.Windows.Media.Brushes.Purple;
                        myRect.StrokeThickness = 7;
                        myRect.HorizontalAlignment = HorizontalAlignment.Left;
                        myRect.VerticalAlignment = VerticalAlignment.Center;
                        
                        int y = i / 11;
                        int x = i % 11;

                        myRect.Height = HAUTEUR_CASE;
                        myRect.Width = LARGEUR_CASE;
                        double marghaut = x * LARGEUR_CASE;
                        double marggauche = y * HAUTEUR_CASE;
                        nbCasesRect++;
                        myRect.Height += 20;
                        myRect.Width += 23;
                        if (x == 10)
                        {
                            marghaut += clickZone.Margin.Left - 5;
                        }
                        if (y == 7)
                        {
                            marggauche += clickZone.Margin.Top - 3;
                        }

                        myRect.Margin = new Thickness(marghaut, marggauche, 0, 0);
                        plateau.Children.Add(myRect);
                        dernierIndexPort = plateau.Children.IndexOf(myRect);
                    }

                        //Display boxes for boat's move.
                    else if (b == 1)
                    {
                        Rectangle myRect = new System.Windows.Shapes.Rectangle();
                        myRect.Stroke = System.Windows.Media.Brushes.Purple;
                        myRect.StrokeThickness = 7;
                        myRect.HorizontalAlignment = HorizontalAlignment.Left;
                        myRect.VerticalAlignment = VerticalAlignment.Center;
                        int y = i / 11;
                        int x = i % 11;
                        nbCasesChoix++;
                        myRect.Height = HAUTEUR_CASE;
                        myRect.Width = LARGEUR_CASE;
                        double marghaut = x * LARGEUR_CASE+2;
                        double marggauche = y * HAUTEUR_CASE+5;

                        myRect.Margin = new Thickness(marghaut, marggauche, 0, 0);

                        clickZone.Children.Add(myRect);
                        dernierIndex = clickZone.Children.IndexOf(myRect);
                    }
                }
            }
            if (FacadeW.afficheBateaux())
            {
               this.BoatUpdate();
            }
           }
        private void init_Jeu(int a)
        {
            Init.Visibility = System.Windows.Visibility.Hidden;

                    
            joueurJaune.Visibility = System.Windows.Visibility.Hidden;
            joueurBleu.Visibility = System.Windows.Visibility.Hidden;
            joueurRouge.Visibility = System.Windows.Visibility.Hidden;
            joueurVert.Visibility = System.Windows.Visibility.Hidden;
            FacadeW.setNbJoueurs(a);
            this.setCases();
            textBlock3.Text = FacadeW.getMessage();
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

        private void BoatUpdate()
        {
            if (FacadeW.afficheScores())
            {
                this.updateScore();
            }
            IntPtr a = new IntPtr(FacadeW.getBateaux().GetHashCode());
            int d = (FacadeW.getNbJoueurs() == 3) ? 3 : 4;
            //Remove the "old" boats.
            plateau.Children.RemoveRange(dernierIndexBateau - nbBateaux + 1, nbBateaux);
            nbBateaux = 0;
            for (int i = 0; i < d; i++)
            {
                int x = Marshal.ReadInt32(a);
                x--;
                a+=sizeof (int);
                int y = Marshal.ReadInt32(a);
                y--;
                a += sizeof(int);
                int tre = Marshal.ReadInt32(a);
                bool tresor = (tre == 1) ? true : false;
                a += sizeof(int);
                int type = Marshal.ReadInt32(a);
                a += sizeof(int);
                int couleur = Marshal.ReadInt32(a);
                //MessageBox.Show("" + x + " " + y + " " + type + " " + tresor + " " + couleur);
                this.afficherBateau(x, y, type, tresor, couleur);
                a += sizeof(int);
            }
        }

        private void clickZone_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        { 
            if(FacadeW.activerCases())
            {
                double a = Mouse.GetPosition(clickZone).X;
                a /= LARGEUR_CASE;
                int x = (int)a + 1;
                double b = Mouse.GetPosition(clickZone).Y;
                b /= HAUTEUR_CASE;
                int y = (int)b + 1;
                FacadeW.setClick(x, y);
                this.setCases();
                this.LanceDes.IsEnabled = FacadeW.activerDes();
                textBlock3.Text = FacadeW.getMessage();
                double num_case = (y - 1) * 11 + x;
            }
        }

        private void LanceDes_Click(object sender, RoutedEventArgs e)
        {
            
            LanceDes.IsEnabled = false;
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
                    LanceDes.IsEnabled = true;
                    _lancerDesTimer.Stop();
                    count = 0;
                    FacadeW.lancerDes();
                    this.LanceDes.IsEnabled = FacadeW.activerDes();
                    this.setCases();
                    textBlock3.Text = FacadeW.getMessage();
                    des1.Source = new BitmapImage(new Uri("Images/face" + FacadeW.getDes1() + ".jpg", UriKind.Relative));
                    des2.Source = new BitmapImage(new Uri("Images/face" + FacadeW.getDes2() + ".jpg", UriKind.Relative));
                    //MessageBox.Show(FacadeW.getDes1() + " " + FacadeW.getDes2());
                }
            };
            _lancerDesTimer.Start();
            if (FacadeW.afficheBateaux())
            {
                this.BoatUpdate();
            }
            
        }

        private void AfficheAide(object sender, RoutedEventArgs e)
        {
            Window2 w = new Window2();
            w.Show();
        }
        private void EnCasDeProbleme(object sender, RoutedEventArgs e)
        {
            String s = "Si vous rencontrez des bugs ou remarquez des erreurs, et même pour toutes suggestions, n'hésitez pas à nous contacter !\n";
            s += "Nicolas Desfeux : nicolas.desfeux@insa-rennes.fr\n";
            s += "Aurélien Texier : aurelien.texier@insa-rennes.fr\n";
            MessageBox.Show(s,"En cas de problèmes",MessageBoxButton.OK,MessageBoxImage.Information);
        }
        private void Apropos(object sender, RoutedEventArgs e)
        {
            String s = "Ici il faudrait mettre les versions, auteur,...";
            MessageBox.Show(s,"A propos");
        }

        private void NouvellePartie(object sender, RoutedEventArgs e)
        {
            MainWindow m = new MainWindow();
            this.Close();
            m.Show();
        }

        private void Quitter(object sender, RoutedEventArgs e)
        {

           MessageBoxResult m = MessageBox.Show("Etes vous sur de vouloir quitter ? (la partie ne sera perdue)","Confirmation", MessageBoxButton.YesNo,MessageBoxImage.Question);

           if(m.ToString() == "Yes")
            this.Close();
        }

    }
}
