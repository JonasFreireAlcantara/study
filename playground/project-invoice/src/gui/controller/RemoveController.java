package gui.controller;

import java.util.ArrayList;

import bean.Debtor;
import bean.Person;
import bean.Product;
import business.SystemFacade;
import gui.GUIApplication;
import javafx.collections.FXCollections;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.MouseEvent;
import javafx.scene.control.TableView;
import javafx.scene.control.TableColumn;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;

public class RemoveController {
	
	private SystemFacade system = SystemFacade.getInstance();

	@FXML
	private TextField debtorNameTextField;
	@FXML
	private Button searchDebtorButton;

	@FXML
	private TableView<Product> purchaseTableView;
	@FXML
	private TableColumn<Product, String> purchaseNameTableColumn;

	@FXML
	private Button removeButton;
	
	@FXML
	private Button backButton;
	
	
	// Debtor to remove purchase
	Debtor debtor;
	// Product to remove
	Product product;
	// ArrayList products of debtor
	ArrayList<Product> products;
	
	
	
	@FXML
	private void initialize() {
		GUIApplication.setTitle("Remover Compra");
		
		searchDebtorButton.disableProperty().bind( debtorNameTextField.textProperty().isEmpty() );
	}
	
	
	
	@FXML
	public void searchDebtorButtonAction() {
		String name = debtorNameTextField.getText();
		debtor = system.debtorSearchForPerson(new Person(name));
		
		if(debtor == null) {
			
			Alert error = new Alert(Alert.AlertType.ERROR);
			error.setTitle("Info");
			error.setHeaderText("Devedor");
			error.setContentText("Devedor não encontrado");
			error.showAndWait();
			
			return;
		}
		
		products = debtor.getProducts();
		
		purchaseTableView.setItems( FXCollections.observableArrayList(products) );
		purchaseNameTableColumn.setCellValueFactory(new PropertyValueFactory<Product, String>("name"));

		// Creation of action event when clicked the table view with the mouse
		purchaseTableView.setOnMouseClicked( new EventHandler<MouseEvent>() {
			
			@Override
			public void handle(MouseEvent event) {
				product = purchaseTableView.getSelectionModel().getSelectedItem();
			}
			
			
		} );
		
	}
	
	
	
	@FXML
	public void removeButtonAction() {
		if(debtor == null || product == null)
			return;
		
		system.debtorRemoveProduct(debtor, product.getName());
		purchaseTableView.setItems( FXCollections.observableArrayList(products));
		debtorNameTextField.clear();
		
		Alert successful = new Alert(Alert.AlertType.INFORMATION);
		successful.setTitle("Info");
		successful.setHeaderText("Compras");
		successful.setContentText("Compra removida com sucesso !");
		successful.showAndWait();
	}
	
	
	
	@FXML
	public void backButtonAction() {
		GUIApplication.backScene();
	}

}
