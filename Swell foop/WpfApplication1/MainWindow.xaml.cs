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
using System.Windows.Media.Animation;

namespace WpfApplication1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public enum colorgroup
        {
            blue, green, red, DarkBlue, Darkgreen, Darkred, none
        }
        public bool IsSecondClick;
        public long score;
        public int rows, cols;
        public static colorgroup[,] colors;
        public List<Tuple<int, int>>[,] clumps;
        public bool[,] visited;
        List<Tuple<int, int>> prevselected;
        public MainWindow()
        {
            InitializeComponent();
            NewGame();
        }

        void NewGame()
        {
            g.Children.RemoveRange(0,g.Children.Count);
            for (int i = 0; i < rows;i++ )
            {
                g.RowDefinitions.RemoveAt(0);
            }
            for (int i = 0; i < cols; i++)
            {
                g.ColumnDefinitions.RemoveAt(0);
            }
            rows = Convert.ToInt32(rowsval.Text);
            cols = Convert.ToInt32(colsval.Text);
            IsSecondClick = false;
            score = 0;
            colors = new colorgroup[rows, cols];
            clumps = new List<Tuple<int, int>>[rows, cols];
            visited = new bool[rows, cols];
            prevselected = null;
            Random r = new Random();
            for (int i = 0; i < rows; i++)
            {
                RowDefinition row = new RowDefinition();
                g.RowDefinitions.Add(row);
            }
            for (int i = 0; i < cols; i++)
            {
                ColumnDefinition col = new ColumnDefinition();
                g.ColumnDefinitions.Add(col);
            }
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    int next = r.Next(3);
                    RoundObject round = new RoundObject(i, j);
                    round.PreviewMouseDown += new MouseButtonEventHandler(Change);
                    Grid.SetRow(round, i);
                    Grid.SetColumn(round, j);
                    g.Children.Add(round);
                    switch (next)
                    {
                        case 0:
                            {
                                setcolor(i, j, colorgroup.blue);
                                break;
                            }
                        case 1:
                            {
                                setcolor(i, j, colorgroup.green);
                                break;
                            }
                        case 2:
                            {
                                setcolor(i, j, colorgroup.red);
                                break;
                            }
                        default:
                            {
                                setcolor(i, j, colorgroup.none);
                                break;
                            }
                    }
                }
            }
            FindClumps();
        }

        void setcolor(int i, int j, colorgroup c, bool shouldchangecolor = true)
        {
            RoundObject round = (g.Children[i * rows + j] as RoundObject);
            colors[i, j] = c;
            if (shouldchangecolor)
            {
                switch (c)
                {
                    case colorgroup.red:
                        (round.EllipseInGrid as Ellipse).Fill = Brushes.Red;
                        break;
                    case colorgroup.blue:
                        (round.EllipseInGrid as Ellipse).Fill = Brushes.Blue;
                        break;
                    case colorgroup.green:
                        (round.EllipseInGrid as Ellipse).Fill = Brushes.Green;
                        break;
                    case colorgroup.Darkred:
                        (round.EllipseInGrid as Ellipse).Fill = Brushes.DarkRed;
                        break;
                    case colorgroup.DarkBlue:
                        (round.EllipseInGrid as Ellipse).Fill = Brushes.DarkBlue;
                        break;
                    case colorgroup.Darkgreen:
                        (round.EllipseInGrid as Ellipse).Fill = Brushes.DarkGreen;
                        break;
                    case colorgroup.none:
                        (round.EllipseInGrid as Ellipse).Fill = null;
                        break;
                }
            }
        }

        private bool TranslateTransformVertical(Ellipse e, double distance)
        {
            this.Show();
            double duration = 6;
            double delay = 0.0;
            TranslateTransform offsetTransform = new TranslateTransform();
            DoubleAnimation offsetAnimation = new DoubleAnimation(0.0, distance, new Duration(TimeSpan.FromSeconds(duration)));
            offsetAnimation.BeginTime = TimeSpan.FromSeconds(delay);
            offsetTransform.BeginAnimation(TranslateTransform.YProperty, offsetAnimation);
            e.RenderTransform = offsetTransform;
            return true;
        }

        private void TranslateTransformHorizontal(Ellipse e, double distance)
        {
            double duration = 6;
            double delay = 0.0;
            TranslateTransform offsetTransform = new TranslateTransform();
            DoubleAnimation offsetAnimation = new DoubleAnimation(0.0, distance, new Duration(TimeSpan.FromSeconds(duration)));
            offsetAnimation.BeginTime = TimeSpan.FromSeconds(delay);
            offsetTransform.BeginAnimation(TranslateTransform.XProperty, offsetAnimation);
            e.RenderTransform = offsetTransform;
        }

        void dfs(int ox, int oy, int i, int j, int count)
        {
            visited[i, j] = true;
            clumps[ox, oy].Add(new Tuple<int, int>(i, j));
            if (count == rows * cols)
                return;
            else
            {
                if (i < rows - 1 && visited[i + 1, j] == false && colors[i + 1, j] == colors[ox, oy])
                {
                    dfs(ox, oy, i + 1, j, count + 1);
                }
                if (j < cols - 1 && visited[i, j + 1] == false && colors[i, j + 1] == colors[ox, oy])
                {
                    dfs(ox, oy, i, j + 1, count + 1);
                }
                if (i > 0 && visited[i - 1, j] == false && colors[i - 1, j] == colors[ox, oy])
                {
                    dfs(ox, oy, i - 1, j, count + 1);
                }
                if (j > 0 && visited[i, j - 1] == false && colors[i, j - 1] == colors[ox, oy])
                {
                    dfs(ox, oy, i, j - 1, count + 1);
                }
            }
        }

        void FindClumps()
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    clumps[i, j] = null;
                    visited[i, j] = false;
                }
            }
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (clumps[i, j] == null)
                    {
                        clumps[i, j] = new List<Tuple<int, int>>();
                        dfs(i, j, i, j, 0);
                        for (int p = 0; p < clumps[i, j].Count; p++)
                        {
                            int x = clumps[i, j][p].Item1;
                            int y = clumps[i, j][p].Item2;
                            clumps[x, y] = clumps[i, j];
                        }
                    }
                }
            }
        }

        void swapcolor(int firstx, int firsty, int secondx, int secondy)
        {
            colorgroup c = colors[firstx, firsty];
            setcolor(firstx, firsty, colors[secondx, secondy]);
            setcolor(secondx, secondy, c);
        }

        void compact()
        {
            for (int i = rows - 1; i >= 0; i--)
            {
                for (int j = cols - 1; j >= 0; j--)
                {
                    if (colors[i, j] == colorgroup.none)
                    {
                        int firstx = i;
                        int firsty = j;
                        int secondx = firstx;
                        int secondy = firsty;
                        while (secondx >= 0 && colors[secondx, secondy] == colorgroup.none)
                        {
                            --secondx;
                        }
                        if (secondx < 0)
                        {
                            int index = 0;
                            for (index = 0; index < rows; index++)
                            {
                                if (colors[index, secondy] != colorgroup.none)
                                {
                                    break;
                                }
                            }
                            if (index == rows)
                            {
                                for (int p = 0; p < rows; p++)
                                {
                                    for (int q = secondy; q < cols - 1; q++)
                                    {
                                        //horizontal shift
                                        swapcolor(p, q, p, q + 1);
                                    }
                                }
                            }
                        }
                        else
                        {
                            Random r = new Random();
                            int fx = firstx, fy = firsty,sx=secondx,sy=secondy;
                            while (secondx >= 0)
                            {
                                swapcolor(firstx, firsty, secondx, secondy);
                                firstx--;
                                secondx--;
                            }
                        }
                    }
                }
            }
        }

        void Change(object sender, MouseButtonEventArgs e)
        {
            if (!IsSecondClick)
            {
                FindClumps();
            }
            int i = (sender as RoundObject).i;
            int j = (sender as RoundObject).j;
            if (clumps[i, j].Count == 1) return;
            List<Tuple<int, int>> x = clumps[i, j];

            if (IsSecondClick && x == prevselected)
            {
                for (int t = 0; t < x.Count; t++)
                {
                    setcolor(x[t].Item1, x[t].Item2, colorgroup.none);
                }
                compact();
                score += clumps[i, j].Count * clumps[i, j].Count;
                scoreboard.Text = score + "";
                IsSecondClick = false;
            }
            else
            {
                if (IsSecondClick)
                {
                    colorgroup cg = colorgroup.none;
                    switch (colors[prevselected[0].Item1, prevselected[0].Item2])
                    {
                        case colorgroup.DarkBlue:
                            cg = colorgroup.blue;
                            break;
                        case colorgroup.Darkgreen:
                            cg = colorgroup.green;
                            break;
                        case colorgroup.Darkred:
                            cg = colorgroup.red;
                            break;
                    }
                    for (int t = 0; t < prevselected.Count; t++)
                    {
                        setcolor(prevselected[t].Item1, prevselected[t].Item2, cg);
                    }
                }
                for (int t = 0; t < x.Count; t++)
                {
                    if (colors[x[t].Item1, x[t].Item2] == colorgroup.blue)
                        setcolor(x[t].Item1, x[t].Item2, colorgroup.DarkBlue);
                    if (colors[x[t].Item1, x[t].Item2] == colorgroup.green)
                        setcolor(x[t].Item1, x[t].Item2, colorgroup.Darkgreen);
                    if (colors[x[t].Item1, x[t].Item2] == colorgroup.red)
                        setcolor(x[t].Item1, x[t].Item2, colorgroup.Darkred);
                }
                IsSecondClick = true;
                prevselected = x;
            }
        }

        private void NewGame_Click(object sender, RoutedEventArgs e)
        {
            scoreboard.Text = "0";
            NewGame();
        }
    }
}
