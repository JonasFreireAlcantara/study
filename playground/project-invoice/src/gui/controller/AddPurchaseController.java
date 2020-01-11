package gui.controller;

import business.SystemFacade;

import gui.GUIApplication;

import javafx.fxml.FXML;
import javafx.scene.control.TextField;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;

public class AddPurchaseController {
	
	SystemFacade system = SystemFacade.getInstance();

	@FXML
	private TextField namePurchaseTextField;
	@FXML
	private TextField priceTextField;
	@FXML
	private TextField installmentsAmountTextField;
	@FXML
	private TextField debtorTextField;
	
	@FXML
	private Button addButton;
	@FXML
	private Button backButton;
	
	
	@FXML
	private void initialize() {
		GUIApplication.setTitle("Adicionar Compra");
	}


	@FXML
	public void addButtonAction() {
		String personName = this.debtorTextField.getText();
		String productName = this.namePurchaseTextField.getText();
		double price;
		int installmentsAmount;
		
		try { // Try convert numerical data
			price = Double.parseDouble(this.priceTextField.getText());
			installmentsAmount = Integer.parseInt(this.installmentsAmountTextField.getText());
		} catch (NumberFormatException nbe) {
			Alert error = new Alert(Alert.AlertType.ERROR);
			error.setTitle("Info");
			error.setHeaderText("Compras");
			error.setContentText("Por favor corrija os dados");
			error.showAndWait();
			return;
		}
		
		try {
			this.system.debtorNewAcquisition(personName, productName, price, installmentsAmount);
		} catch( Exception exception ) {
			Alert error = new Alert(Alert.AlertType.ERROR);
			error.setTitle("Info");
			error.setHeaderText("Compras");
			error.setContentText(exception.getMessage());
			error.showAndWait();
		}
		
		Alert success = new Alert(Alert.AlertType.INFORMATION);
		success.setTitle("Info");
		success.setHeaderText("Compras");
		success.setContentText("Compra adicionada com sucesso !");
		success.showAndWait();
			
	}


	@FXML
	public void backButtonAction() {
		GUIApplication.backScene();
	}

	
}
