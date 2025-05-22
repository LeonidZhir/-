using System;
using System.Collections.Generic;
using System.Drawing;

namespace BinarySearchTreeApp
{
    public class TreeNode
    {
        public char Key;
        public TreeNode Left, Right;
        public int Height;

        public TreeNode(char key)
        {
            Key = key;
            Left = Right = null;
            Height = 1;
        }
    }

    public class BinarySearchTree
    {
        private TreeNode root;

        private int Height(TreeNode node) => node?.Height ?? 0;

        private int BalanceFactor(TreeNode node) => Height(node.Right) - Height(node.Left);

        private void UpdateHeight(TreeNode node)
        {
            node.Height = Math.Max(Height(node.Left), Height(node.Right)) + 1;
        }

        private TreeNode RotateRight(TreeNode p)
        {
            TreeNode q = p.Left;
            p.Left = q.Right;
            q.Right = p;
            UpdateHeight(p);
            UpdateHeight(q);
            return q;
        }

        private TreeNode RotateLeft(TreeNode q)
        {
            TreeNode p = q.Right;
            q.Right = p.Left;
            p.Left = q;
            UpdateHeight(q);
            UpdateHeight(p);
            return p;
        }

        private TreeNode Balance(TreeNode node)
        {
            UpdateHeight(node);
            int balance = BalanceFactor(node);

            if (balance == 2)
            {
                if (BalanceFactor(node.Right) < 0)
                    node.Right = RotateRight(node.Right);
                return RotateLeft(node);
            }
            if (balance == -2)
            {
                if (BalanceFactor(node.Left) > 0)
                    node.Left = RotateLeft(node.Left);
                return RotateRight(node);
            }

            return node;
        }

        public void Insert(char key)
        {
            root = Insert(root, key);
        }

        private TreeNode Insert(TreeNode node, char key)
        {
            if (node == null) return new TreeNode(key);
            if (key < node.Key)
                node.Left = Insert(node.Left, key);
            else if (key > node.Key)
                node.Right = Insert(node.Right, key);
            else
                return node; // дубликаты не добавляем
            return Balance(node);
        }

        public void Remove(char key)
        {
            root = Remove(root, key);
        }

        private TreeNode FindMin(TreeNode node)
        {
            return node.Left == null ? node : FindMin(node.Left);
        }

        private TreeNode RemoveMin(TreeNode node)
        {
            if (node.Left == null)
                return node.Right;
            node.Left = RemoveMin(node.Left);
            return Balance(node);
        }

        private TreeNode Remove(TreeNode node, char key)
        {
            if (node == null) return null;
            if (key < node.Key)
                node.Left = Remove(node.Left, key);
            else if (key > node.Key)
                node.Right = Remove(node.Right, key);
            else
            {
                TreeNode left = node.Left;
                TreeNode right = node.Right;
                if (right == null) return left;
                TreeNode min = FindMin(right);
                min.Right = RemoveMin(right);
                min.Left = left;
                return Balance(min);
            }
            return Balance(node);
        }

        // Обходы
        public List<char> PreOrder()
        {
            var res = new List<char>();
            PreOrder(root, res);
            return res;
        }
        private void PreOrder(TreeNode node, List<char> res)
        {
            if (node == null) return;
            res.Add(node.Key);
            PreOrder(node.Left, res);
            PreOrder(node.Right, res);
        }

        public List<char> InOrder()
        {
            var res = new List<char>();
            InOrder(root, res);
            return res;
        }
        private void InOrder(TreeNode node, List<char> res)
        {
            if (node == null) return;
            InOrder(node.Left, res);
            res.Add(node.Key);
            InOrder(node.Right, res);
        }

        public List<char> PostOrder()
        {
            var res = new List<char>();
            PostOrder(root, res);
            return res;
        }
        private void PostOrder(TreeNode node, List<char> res)
        {
            if (node == null) return;
            PostOrder(node.Left, res);
            PostOrder(node.Right, res);
            res.Add(node.Key);
        }

        // Подсчёт вхождений
        public int CountOccurrences(char key)
        {
            return CountOccurrences(root, key);
        }
        private int CountOccurrences(TreeNode node, char key)
        {
            if (node == null) return 0;
            int count = (node.Key == key) ? 1 : 0;
            return count + CountOccurrences(node.Left, key) + CountOccurrences(node.Right, key);
        }

        // Печать дерева в консоль (горизонтально)
        public void PrintHorizontal()
        {
            PrintHorizontal(root, 0);
        }
        private void PrintHorizontal(TreeNode node, int level)
        {
            if (node == null) return;
            PrintHorizontal(node.Right, level + 1);
            Console.WriteLine(new string(' ', 4 * level) + node.Key);
            PrintHorizontal(node.Left, level + 1);
        }

        // Печать дерева в консоль (вертикально)
        public void PrintVertical()
        {
            PrintVertical(root, "", false);
        }
        private void PrintVertical(TreeNode node, string prefix, bool isLeft)
        {
            if (node == null) return;
            Console.WriteLine(prefix + (isLeft ? "├── " : "└── ") + node.Key);
            PrintVertical(node.Left, prefix + (isLeft ? "│   " : "    "), true);
            PrintVertical(node.Right, prefix + (isLeft ? "│   " : "    "), false);
        }

        // Визуализация (оставим как есть)
        public void Draw(Graphics g, int x, int y, int hGap, int vGap)
        {
            DrawTree(g, root, x, y, hGap, vGap);
        }
        private void DrawTree(Graphics g, TreeNode node, int x, int y, int hGap, int vGap)
        {
            if (node == null) return;

            if (node.Left != null)
            {
                g.DrawLine(Pens.Black, x, y, x - hGap, y + vGap);
                DrawTree(g, node.Left, x - hGap, y + vGap, hGap / 2, vGap);
            }
            if (node.Right != null)
            {
                g.DrawLine(Pens.Black, x, y, x + hGap, y + vGap);
                DrawTree(g, node.Right, x + hGap, y + vGap, hGap / 2, vGap);
            }

            g.FillEllipse(Brushes.White, x - 20, y - 20, 40, 40);
            g.DrawEllipse(Pens.Black, x - 20, y - 20, 40, 40);
            g.DrawString(node.Key.ToString(), new Font("Arial", 12), Brushes.Black, x - 7, y - 12);
        }
    }
}
