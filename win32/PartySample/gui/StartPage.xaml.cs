using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace PartySample
{
    /// <summary>
    /// Interaction logic for StartPage.xaml
    /// </summary>
    public partial class StartPage : Page
    {
        public StartPage()
        {
            InitializeComponent();
        }

        private void OnClickInitializeButton(object sender, RoutedEventArgs e)
        {
            StartPageTextBoxError.Text = "";

            string titleId = TitleIdTextBox.Text;
            if (titleId == "")
            {
                StartPageTextBoxError.Text = "Must provide a PlayFab Title ID in the text box!";
                return;
            }

            string playFabPlayerCustomId = PlayerCustomIdDropDown.Text;

            App.appWindow.AppWindowFrame.Navigate(new PartySamplePage(titleId, playFabPlayerCustomId));
        }
    }
}
