import java.awt.*;
import javax.swing.*;
import java.awt.image.*;
import java.awt.event.*;
import java.awt.Color;
import javax.swing.text.*;

class Fr extends Frame
{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	Image img;
	int pixels[];
	int histr[]=new int[256];
	int histg[]=new int[256];
	int histb[]=new int[256];
	int iw,ih;
	pix f;
	JButton b1;

	Document doc;

	SimpleAttributeSet rd;
    SimpleAttributeSet gr;
    SimpleAttributeSet bl;

	public Fr()
	{
		super("Histogram");
		
		setSize(1370,730);
		MyWindowAdapter wa=new MyWindowAdapter(this);
		addWindowListener(wa);

		try
		{
			img=getToolkit().getImage("cricket.png");
			MediaTracker t = new MediaTracker(this);
			t.addImage(img, 0);
			t.waitForID(0);
			iw=img.getWidth(null);
			ih=img.getHeight(null);
			pixels=new int[iw*ih];
// 			public PixelGrabber(Image img,
//             int x,
//             int y,
//             int w,
//             int h,
//             int[] pix,
//             int off,
//             int scansize)
// Create a PixelGrabber object to grab the (x, y, w, h) rectangular section of pixels from the specified image into the given array. The pixels are stored into the array in the default RGB ColorModel. The RGB data for pixel (i, j) where (i, j) is inside the rectangle (x, y, w, h) is stored in the array at pix[(j - y) * scansize + (i - x) + off].
// Parameters:
// img - the image to retrieve pixels from
// x - the x coordinate of the upper left corner of the rectangle of pixels to retrieve from the image, relative to the default (unscaled) size of the image
// y - the y coordinate of the upper left corner of the rectangle of pixels to retrieve from the image
// w - the width of the rectangle of pixels to retrieve
// h - the height of the rectangle of pixels to retrieve
// pix - the array of integers which are to be used to hold the RGB pixels retrieved from the image
// off - the offset into the array of where to store the first pixel
// scansize - the distance from one row of pixels to the next in the array
			PixelGrabber pg=new PixelGrabber(img,0,0,iw,ih,pixels,0,iw);
			pg.grabPixels();
		}
		catch(InterruptedException e){}

		f=new pix();
		b1=new JButton("View pixel values");
		b1.addActionListener(new ActionListener() 
	        	{
		            	public void actionPerformed(ActionEvent e)
	            		{
    		      			f.setVisible(true);
    		      			
   	        			}	

	        	});

		rd = new SimpleAttributeSet();
        gr = new SimpleAttributeSet();
        bl = new SimpleAttributeSet();

        StyleConstants.setFontSize(rd, 14);
        StyleConstants.setForeground(rd, Color.red);
        StyleConstants.setFontSize(gr, 14);
        StyleConstants.setForeground(gr, Color.green);
        StyleConstants.setFontSize(bl, 14);
        StyleConstants.setForeground(bl,Color.blue);

  		doc = f.jtp.getDocument();

		for(int i=0;i<iw*ih;i++)
		{
			int p=pixels[i];
			int r=0xff & (p>>16);
			int g=0xff & (p>>8);
			int b=0xff & (p);

			try
			{
				String s="  "+r;
				doc.insertString(f.jtp.getCaretPosition(),s,rd);
				s="  "+g;
				doc.insertString(f.jtp.getCaretPosition(),s,gr);
				s="  "+b;
				doc.insertString(f.jtp.getCaretPosition(),s,bl);
			}
			catch(Exception evt)
	        {
	            evt.printStackTrace();
	        }
			histr[r]++;
			histg[g]++;
			histb[b]++;
		}

	setVisible(true);
	setLayout(null);
	add(b1);
	b1.setBounds(1200,50,100,50);

	}
	public void paint(Graphics g)
	{
		g.drawLine(0,650,1300,650);
		for(int i=0;i<256;i++)
		{
			g.setColor(Color.red);
			int p=(int)(650-histr[i]);
			g.drawLine(100+i,650,100+i,p);

			 p=(int)(650-histg[i]);
			g.setColor(Color.green);
			g.drawLine(400+i,650,400+i,p);

			 p=(int)(650-histb[i]);
			g.setColor(Color.blue);
			g.drawLine(700+i,650,700+i,p);


		}
		g.drawImage(img,30,30,200,200,this);
	}


public static void main(String args[])
	{
		new Fr();
	}

}

class MyWindowAdapter extends WindowAdapter
{
	Fr f;
	public MyWindowAdapter(Fr f)
	{
		this.f=f;
	}
	public void windowClosing(WindowEvent we) {
			System.exit(0);						
	}

}

class pix extends JFrame
{

    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public pix()
    {
        super("pixel values");
        setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
        jtp = new JTextPane();
        getContentPane().add(new JScrollPane(jtp), "Center");
        setBounds(200, 200, 500, 400);
    }

    JTextPane jtp;
}
