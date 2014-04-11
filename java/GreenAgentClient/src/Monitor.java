import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JScrollPane;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;


public class Monitor extends JFrame {

	private JPanel contentPane;
	private Locations loc;
	private Monitor mon=this;
	public Login login;



	/**
	 * Create the frame.
	 */
	public Monitor(Locations l, Login lo) {
		
		login=lo;
		loc=l;
		
		loc.setVisible(false);
		setTitle("Monitor");
		try {
			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (InstantiationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (UnsupportedLookAndFeelException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 283, 465);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblLogout = new JLabel("Logout");
		lblLogout.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				
			mon.setVisible(false);
			login.setVisible(true);
				
			}
		});
		lblLogout.setBounds(130, 21, 83, 36);
		contentPane.add(lblLogout);
		
		ImageIcon imgThisImg = new ImageIcon("Turn Off.png");

		lblLogout.setIcon(imgThisImg);
		
		JLabel lblNewLabel = new JLabel("New label");
		lblNewLabel.setBounds(10, 58, 247, 14);
		contentPane.add(lblNewLabel);
		
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(10, 83, 247, 282);
		contentPane.add(scrollPane);
		
		JPanel panel = new JPanel();
		scrollPane.setColumnHeaderView(panel);
		
		JLabel lblBack = new JLabel("Back");
		lblBack.setBounds(117, 391, 59, 14);
		contentPane.add(lblBack);
		
		
	}

}
