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

namespace WpfApplication1
{
    /// <summary>
    /// Interaction logic for RoundObject.xaml
    /// </summary>
    public partial class RoundObject : UserControl
    {
        
        public int i, j;
        public RoundObject()
        {
            InitializeComponent();
        }
        public RoundObject(int i,int j)
        {
            
            this.i = i;
            this.j = j;
            InitializeComponent();
        }

        private void ButtonInGrid_Click(object sender, RoutedEventArgs e)
        {
            //MessageBox.Show(""+MainWindow.colors[i,j]);
        }
    }
}
