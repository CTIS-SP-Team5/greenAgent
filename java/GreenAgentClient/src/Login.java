import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.Frame;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JComboBox;
import javax.swing.JButton;
import javax.swing.JToggleButton;
import javax.swing.JCheckBox;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import javax.swing.JLabel;
import javax.swing.JTextField;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JPasswordField;


public class Login extends JFrame {

	private JPanel contentPane;
	private JTextField textField;
	private JTextField textField_2;
	private JTextField textField_3;
	
	private Login mf=this;
	private Monitor mon;
	
	//en son monitor ekranýndan login ekranýna dönüþ yapýldý.
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Login frame = new Login();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	Locations loc =new Locations(mf);
	private JTextField textField_4;
	private JPasswordField passwordField;
	public Login() {
		setTitle("Login");
		
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
		
	
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 261, 365);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblUsername = new JLabel("Username:");
		lblUsername.setBounds(63, 29, 117, 14);
		contentPane.add(lblUsername);
		
		textField = new JTextField();
		textField.setBounds(63, 54, 117, 20);
		contentPane.add(textField);
		textField.setColumns(10);
		
		JLabel lblPassword = new JLabel("Password:");
		lblPassword.setBounds(63, 85, 117, 14);
		contentPane.add(lblPassword);
		
		JLabel lblHostAddress = new JLabel("Host Address:");
		lblHostAddress.setBounds(63, 141, 117, 14);
		contentPane.add(lblHostAddress);
		
		textField_2 = new JTextField();
		textField_2.setBounds(63, 166, 117, 20);
		contentPane.add(textField_2);
		textField_2.setColumns(10);
		
		JLabel lblNewLabel = new JLabel("Port:");
		lblNewLabel.setBounds(63, 200, 46, 14);
		contentPane.add(lblNewLabel);
		
		textField_3 = new JTextField();
		textField_3.setBounds(107, 197, 73, 20);
		contentPane.add(textField_3);
		textField_3.setColumns(10);
		
		JButton btnLogin = new JButton("Login");
		btnLogin.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				
				String user;
				String pass;
				String host;
				String port;
				
				user=textField.getText();
				pass=new String(passwordField.getPassword());
				host=textField_2.getText();
				port=textField_3.getText();
				
				if(user.compareTo("admin") == 0 && pass.compareTo("1234") == 0){
					loc.setVisible(true);
					mf.setVisible(false);
					
					
				}
				else{
					textField_4.setText("incorrect data");
				}
				textField_4.setText(null);
			}
		});
		btnLogin.setBounds(63, 256, 117, 23);
		contentPane.add(btnLogin);
		
		textField_4 = new JTextField();
		textField_4.setBounds(73, 296, 86, 20);
		contentPane.add(textField_4);
		textField_4.setColumns(10);
		
		passwordField = new JPasswordField();
		passwordField.setBounds(63, 110, 117, 20);
		contentPane.add(passwordField);
	}
}
