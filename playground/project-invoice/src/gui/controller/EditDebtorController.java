package gui.controller;

import bean.Debtor;
import bean.Person;
import business.SystemFacade;
import gui.GUIApplication;
import javafx.collections.FXCollections;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.MouseEvent;

public class EditDebtorController {
	
	private SystemFacade system = SystemFacade.getInstance();
	
	// Useful
	Debtor debtor;

	@FXML
	private TextField nameTextField;
	@FXML
	private Button updateButton;

	@FXML
	private TableView<Debtor> debtorTableView;
	@FXML
	private TableColumn<Debtor, String> debtorNameTableColumn;

	@FXML
	private Button backButton;
	
	
	@FXML
	private void initialize() {
		GUIApplication.setTitle("Editar Devedor");
		
		updateButton.disableProperty().bind( nameTextField.textProperty().isEmpty() ); // While nameTextField is empty
		
		debtorTableView.setItems( FXCollections.observableArrayList(this.system.debtorsGetDebtors()) );
		debtorNameTableColumn.setCellValueFactory(new PropertyValueFactory<Debtor, String>("name"));
		
		debtorTableView.setOnMouseClicked(new EventHandler<MouseEvent>() {
			
			@Override
			public void handle(MouseEvent event) {
				debtor = debtorTableView.getSelectionModel().getSelectedItem();
				nameTextField.setText(debtor.getName());
			}
			
		});
		
		
	}
	
	
	
		
	
	@FXML
	public void backButtonAction() {
		GUIApplication.backScene();
	}
	
	
	


	@FXML
	public void updateButtonAction() {
		Person newPerson = new Person(nameTextField.getText());
		try {
			system.debtorUpdateDebtor(debtor, newPerson);
		} catch(Exception e) {
			Alert error = new Alert(Alert.AlertType.ERROR);
			error.setTitle("Erro");
			error.setHeaderText("Compra");
			error.setContentText(e.getMessage());
			error.showAndWait();
			return;
		}
		
		debtorTableView.refresh();
		Alert success = new Alert(Alert.AlertType.INFORMATION);
		success.setTitle("Info");
		success.setHeaderText("Devedor");
		success.setContentText("Atualização efetuada com sucesso !");
		success.showAndWait();
	}
	
	
	

}
