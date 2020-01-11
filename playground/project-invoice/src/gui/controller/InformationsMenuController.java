package gui.controller;

import gui.GUIApplication;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;

public class InformationsMenuController {

	@FXML
	private Button debtorButton;
	@FXML
	private Button purchaseButton;
	@FXML
	private Button backButton;
	
	
	@FXML
	private void initialize() {
		GUIApplication.setTitle("Informações");
	}
	
	
	
	@FXML
	public void backButtonAction() {
		GUIApplication.backScene();
	}
	
	
	@FXML
	public void debtorButtonAction() throws Exception {
		Parent root = FXMLLoader.load(getClass().getResource("../fxml/InformationsDebtorLayout.fxml"));
		
		GUIApplication.setScene(new Scene(root));			
	}
	
	
	
	@FXML
	public void purchaseButtonAction() throws Exception {
		Parent root = FXMLLoader.load(getClass().getResource("../fxml/InformationsPurchaseLayout.fxml"));
		
		GUIApplication.setScene(new Scene(root));
	}

	
	
	
}
