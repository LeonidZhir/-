namespace BinarySearchTreeApp
{
    partial class MainForm
    {
        private System.ComponentModel.IContainer components = null;
        private System.Windows.Forms.Button btnInsert;
        private System.Windows.Forms.Button btnRemove;
        private System.Windows.Forms.Button btnPreOrder;
        private System.Windows.Forms.Button btnInOrder;
        private System.Windows.Forms.Button btnPostOrder;
        private System.Windows.Forms.Button btnCount;
        private System.Windows.Forms.Button btnPrintHorizontal;
        private System.Windows.Forms.Button btnPrintVertical;
        private System.Windows.Forms.TextBox txtInput;
        private System.Windows.Forms.TextBox txtOutput;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        private void InitializeComponent()
        {
            btnInsert = new Button();
            btnRemove = new Button();
            btnPreOrder = new Button();
            btnInOrder = new Button();
            btnPostOrder = new Button();
            btnCount = new Button();
            btnPrintHorizontal = new Button();
            btnPrintVertical = new Button();
            txtInput = new TextBox();
            txtOutput = new TextBox();
            SuspendLayout();
            // 
            // btnInsert
            // 
            btnInsert.Location = new Point(12, 12);
            btnInsert.Name = "btnInsert";
            btnInsert.Size = new Size(75, 23);
            btnInsert.TabIndex = 0;
            btnInsert.Text = "Вставить";
            btnInsert.UseVisualStyleBackColor = true;
            btnInsert.Click += btnInsert_Click;
            // 
            // btnRemove
            // 
            btnRemove.Location = new Point(12, 41);
            btnRemove.Name = "btnRemove";
            btnRemove.Size = new Size(75, 23);
            btnRemove.TabIndex = 1;
            btnRemove.Text = "Удалить";
            btnRemove.UseVisualStyleBackColor = true;
            btnRemove.Click += btnRemove_Click;
            // 
            // btnPreOrder
            // 
            btnPreOrder.Location = new Point(12, 70);
            btnPreOrder.Name = "btnPreOrder";
            btnPreOrder.Size = new Size(120, 23);
            btnPreOrder.TabIndex = 2;
            btnPreOrder.Text = "Прямой обход";
            btnPreOrder.UseVisualStyleBackColor = true;
            btnPreOrder.Click += btnPreOrder_Click;
            // 
            // btnInOrder
            // 
            btnInOrder.Location = new Point(12, 99);
            btnInOrder.Name = "btnInOrder";
            btnInOrder.Size = new Size(120, 23);
            btnInOrder.TabIndex = 3;
            btnInOrder.Text = "Симметричный обход";
            btnInOrder.UseVisualStyleBackColor = true;
            btnInOrder.Click += btnInOrder_Click;
            // 
            // btnPostOrder
            // 
            btnPostOrder.Location = new Point(12, 128);
            btnPostOrder.Name = "btnPostOrder";
            btnPostOrder.Size = new Size(120, 23);
            btnPostOrder.TabIndex = 4;
            btnPostOrder.Text = "Обратный обход";
            btnPostOrder.UseVisualStyleBackColor = true;
            btnPostOrder.Click += btnPostOrder_Click;
            // 
            // btnCount
            // 
            btnCount.Location = new Point(12, 157);
            btnCount.Name = "btnCount";
            btnCount.Size = new Size(120, 23);
            btnCount.TabIndex = 5;
            btnCount.Text = "Подсчитать вхождения";
            btnCount.UseVisualStyleBackColor = true;
            btnCount.Click += btnCount_Click;
            // 
            // btnPrintHorizontal
            // 
            btnPrintHorizontal.Location = new Point(12, 186);
            btnPrintHorizontal.Name = "btnPrintHorizontal";
            btnPrintHorizontal.Size = new Size(120, 23);
            btnPrintHorizontal.TabIndex = 6;
            btnPrintHorizontal.Text = "Печать горизонтально";
            btnPrintHorizontal.UseVisualStyleBackColor = true;
            btnPrintHorizontal.Click += btnPrintHorizontal_Click;
            // 
            // btnPrintVertical
            // 
            btnPrintVertical.Location = new Point(12, 215);
            btnPrintVertical.Name = "btnPrintVertical";
            btnPrintVertical.Size = new Size(120, 23);
            btnPrintVertical.TabIndex = 7;
            btnPrintVertical.Text = "Печать вертикально";
            btnPrintVertical.UseVisualStyleBackColor = true;
            btnPrintVertical.Click += btnPrintVertical_Click;
            // 
            // txtInput
            // 
            txtInput.Location = new Point(138, 14);
            txtInput.Name = "txtInput";
            txtInput.Size = new Size(50, 27);
            txtInput.TabIndex = 8;
            // 
            // txtOutput
            // 
            txtOutput.Location = new Point(12, 331);
            txtOutput.Multiline = true;
            txtOutput.Name = "txtOutput";
            txtOutput.ScrollBars = ScrollBars.Vertical;
            txtOutput.Size = new Size(435, 177);
            txtOutput.TabIndex = 9;
            // 
            // MainForm
            // 
            ClientSize = new Size(1153, 579);
            Controls.Add(txtOutput);
            Controls.Add(txtInput);
            Controls.Add(btnPrintVertical);
            Controls.Add(btnPrintHorizontal);
            Controls.Add(btnCount);
            Controls.Add(btnPostOrder);
            Controls.Add(btnInOrder);
            Controls.Add(btnPreOrder);
            Controls.Add(btnRemove);
            Controls.Add(btnInsert);
            Name = "MainForm";
            Text = "Сбалансированное бинарное дерево поиска";
            ResumeLayout(false);
            PerformLayout();
        }
    }
}
