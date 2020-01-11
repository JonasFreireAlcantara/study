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
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.MouseEvent;
import javafx.scene.control.TableView;
import javafx.scene.control.TableColumn;

public class EditPurchaseController {
	
	private SystemFacade system = SystemFacade.getInstance();

	@FXML
	private Button updateButton;
	@FXML
	private Button searchButton;

	@FXML
	private TextField debtorNameTextField;

	@FXML
	private TableView<Product> purchaseTableView;
	@FXML
	private TableColumn<Product, String> purchaseTableColumn;
	
	@FXML
	private TextField purchaseNameTextField;
	@FXML
	private TextField pricePerInstallmentTextField;
	@FXML
	private TextField installmentsAmountTextField;
	@FXML
	private TextField actualInstallmentTextField;
	@FXML
	private TextField totalPriceTextField;
	@FXML
	private TextField dateDayTextField;
	@FXML
	private TextField dateMonthTextField;
	@FXML
	private TextField dateYearTextField;
	
	@FXML
	private Button backButton;


	// Debtor owner of below product
	private Debtor debtor;
	// Product to edit
	private Product product;
	
	
	@FXML
	private void initialize() {
		GUIApplication.setTitle("Editar Compras");
		
		searchButton.disableProperty().bind(debtorNameTextField.textProperty().isEmpty());
		updateButton.disableProperty().bind( purchaseNameTextField.textProperty().isEmpty().or(
											 pricePerInstallmentTextField.textProperty().isEmpty().or(
											 installmentsAmountTextField.textProperty().isEmpty().or(
											 actualInstallmentTextField.textProperty().isEmpty().or(
											 dateDayTextField.textProperty().isEmpty().or(
											 dateMonthTextField.textProperty().isEmpty().or(
											 dateYearTextField.textProperty().isEmpty().or(
											 totalPriceTextField.textProperty().isEmpty() ))))))));
		
		
		purchaseTableView.setOnMouseClicked( new EventHandler<MouseEvent>() {
			
			@Override
			public void handle(MouseEvent event) {
				product = purchaseTableView.getSelectionModel().getSelectedItem();
				
				purchaseNameTextField.setText(product.getName());
				pricePerInstallmentTextField.setText( Double.toString(product.getPrice()) );
				installmentsAmountTextField.setText( Integer.toString(product.getInstallmentsAmount()) );
				actualInstallmentTextField.setText( Integer.toString(product.getActualInstallment()) );
				dateDayTextField.setText( Integer.toString(product.getDate().get(Calendar.DAY_OF_MONTH) ));
				dateMonthTextField.setText( Integer.toString( product.getDate().get(Calendar.MONTH) ));
				dateYearTextField.setText( Integer.toString( product.getDate().get(Calendar.YEAR) ));
				totalPriceTextField.setText( Double.toString( product.getPrice() * product.getInstallmentsAmount() ) );
			}
			
			
	});
		
	}



	@FXML
	public void backButtonAction() {
		GUIApplication.backScene();
	}



	@FXML
	public void searchButtonAction() {
		String name = debtorNameTextField.getText();
		debtor = system.debtorSearchForPerson(new Person(name));
		
		if(debtor == null) {
			Alert error = new Alert(Alert.AlertType.ERROR);
			error.setTitle("Info");
			error.setHeaderText("Compras");
			error.setContentText("Devedor não encontrado");
			error.showAndWait();
			return;
		}
		
		ArrayList<Product> products = debtor.getProducts();
		
		purchaseTableView.setItems( FXCollections.observableArrayList(products) );
		purchaseTableColumn.setCellValueFactory(new PropertyValueFactory<Product, String>("name"));
	}



	@FXML
	public void updateButtonAction() {
		if( product == null ) {
			return; // TODO create a pop-up
		}
		
		Product newProduct = new Product( purchaseNameTextField.getText() );
		
		try {
			newProduct.setPrice( Double.parseDouble(pricePerInstallmentTextField.getText()));
			newProduct.setInstallmentsAmount( Integer.parseInt(installmentsAmountTextField.getText()) );
			newProduct.setActualInstallment( Integer.parseInt(actualInstallmentTextField.getText()) );
			
			Calendar newDate = Calendar.getInstance();
			newDate.set(Calendar.DAY_OF_MONTH, Integer.parseInt(dateDayTextField.getText()));
			newDate.set(Calendar.MONTH, Integer.parseInt(dateMonthTextField.getText()));
			newDate.set(Calendar.YEAR, Integer.parseInt(dateYearTextField.getText()));
			
			newProduct.setDate(newDate);
	
		} catch(NumberFormatException nfe) {
			Alert error = new Alert(Alert.AlertType.ERROR);
			error.setTitle("Info");
			error.setHeaderText("Compras");
			error.setContentText("Por favor corrija os dados");
			error.showAndWait();
			return;
		}
		
		try {
			system.debtorUpdateDebtor(debtor, product, newProduct);
		} catch (Exception e) {
			Alert error = new Alert(Alert.AlertType.ERROR);
			error.setTitle("Erro");
			error.setHeaderText("Compras");
			error.setContentText(e.getMessage());
			error.showAndWait();
			return;
		}
		
		purchaseTableView.refresh();
		Alert success = new Alert(Alert.AlertType.INFORMATION);
		success.setTitle("Info");
		success.setHeaderText("Compras");
		success.setContentText("Compra atualizada com sucesso !");
		success.showAndWait();
	}
	
	
	
	
	
}
