package gui.controller;

import java.io.IOException;

import gui.GUIApplication;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;

public class EditMenuController {

	@FXML
	private Button debtorButton;
	@FXML
	private Button purchaseButton;
	
	@FXML
	private Button backButton;
	
	
	@FXML
	private void initialize() {
		GUIApplication.setTitle("Editar");
	}
	
	
	@FXML
	public void backButtonAction() {
		GUIApplication.backScene();
	}


	@FXML
	public void debtorButtonAction() throws IOException {
		Parent root = FXMLLoader.load(getClass().getResource("../fxml/EditDebtorLayout.fxml"));
		GUIApplication.setScene(new Scene(root));
	}


	@FXML
	public void purchaseButtonAction() throws IOException {
		Parent root = FXMLLoader.load(getClass().getResource("../fxml/EditPurchaseLayout.fxml"));
		GUIApplication.setScene(new Scene(root));
	}
	
}
