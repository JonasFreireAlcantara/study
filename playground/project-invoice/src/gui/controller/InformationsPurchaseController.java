package gui.controller;

import java.util.ArrayList;
import java.util.Calendar;

import bean.Debtor;
import bean.Person;
import bean.Product;
import business.SystemFacade;
import gui.GUIApplication;
import javafx.collections.FXCollections;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.MouseEvent;
import javafx.scene.control.TableView;
import javafx.scene.control.TableColumn;

public class InformationsPurchaseController {
	
	private SystemFacade system = SystemFacade.getInstance();

	@FXML
	private Label nameLabel;
	@FXML
	private Label pricePerMonthLabel;
	@FXML
	private Label installmentsAmountLabel;
	@FXML
	private Label actualInstallmentLabel;
	@FXML
	private Label dateLabel;
	@FXML
	private Label totalPriceLabel;

	@FXML
	private TextField nameDebtorTextField;
	@FXML
	private Button searchButton;
	
	@FXML
	private TableView<Product> purchaseTableView;
	@FXML
	private TableColumn<Product, String> namePurchaseTableColumn;

	@FXML
	private Button backButton;

	
	
	@FXML
	private void initialize() {
		GUIApplication.setTitle("Informações Compras");
		
		searchButton.disableProperty().bind( nameDebtorTextField.textProperty().isEmpty() );
		
		
		purchaseTableView.setOnMouseClicked( new EventHandler<MouseEvent>() {
			
			@Override
			public void handle( MouseEvent event ) {
				Product product = purchaseTableView.getSelectionModel().getSelectedItem();
				
				nameLabel.setText(product.getName());
				pricePerMonthLabel.setText( Double.toString(product.getPrice()) );
				installmentsAmountLabel.setText( Integer.toString(product.getInstallmentsAmount()) );
				actualInstallmentLabel.setText( Integer.toString( product.getActualInstallment()) );
				totalPriceLabel.setText( Double.toString(product.getTotalPrice()));
				
				String date = product.getDate().get(Calendar.DAY_OF_MONTH) + " / "
							+ product.getDate().get(Calendar.MONTH) + " / "
							+ product.getDate().get(Calendar.YEAR);
				
				dateLabel.setText(date);
				
			}
			
			
		});
		
	}
	
	
	
	@FXML public void backButtonAction() {
		GUIApplication.backScene();
	}

	@FXML public void searchButtonAction() {
		String name = nameDebtorTextField.getText();
		Debtor debtor = system.debtorSearchForPerson(new Person(name));
		
		if( debtor == null ) {
			
			Alert error = new Alert(Alert.AlertType.ERROR);
			error.setTitle("Info");
			error.setHeaderText("Compras");
			error.setContentText("Devedor não encontrado");
			error.showAndWait();
			
			return;
		}
		
		ArrayList<Product> products = debtor.getProducts();
		
		purchaseTableView.setItems( FXCollections.observableArrayList(products));
		namePurchaseTableColumn.setCellValueFactory(new PropertyValueFactory<Product, String>("name"));
	}
	
	
	
	
	
	
}
