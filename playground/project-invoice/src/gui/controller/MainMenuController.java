package gui.controller;

import java.io.IOException;

import gui.GUIApplication;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;

public class MainMenuController {
	
	@FXML
	private Button addButton;
	@FXML
	private Button removeButton;
	@FXML
	private Button editButton;
	@FXML
	private Button infoButton;
	@FXML
	private Button relaButton;
	@FXML
	private Button quitButton;
	
	
	@FXML
	private void initialize() {
		GUIApplication.setTitle("Programa Fatura");
	}
	
	
	@FXML
	public void addButtonAction() throws IOException {
		Parent root = FXMLLoader.load(getClass().getResource("../fxml/AddPurchaseLayout.fxml"));
		GUIApplication.setScene(new Scene(root));
	}
	
	
	@FXML
	public void removeButtonAction() throws IOException {
		Parent root = FXMLLoader.load(getClass().getResource("../fxml/RemoveLayout.fxml"));
		GUIApplication.setScene(new Scene(root));
	}
	
	
	@FXML
	public void infoButtonAction() throws IOException {
		Parent root = FXMLLoader.load(getClass().getResource("../fxml/InformationsMenuLayout.fxml"));
		GUIApplication.setScene(new Scene(root));
	}
	
	
	@FXML
	public void relaButtonAction() throws IOException {
		Parent root = FXMLLoader.load(getClass().getResource("../fxml/RelatoryLayout.fxml"));
		GUIApplication.setScene(new Scene(root));
	}
	
	
	@FXML
	public void editButtonAction() throws IOException {
		Parent root = FXMLLoader.load(getClass().getResource("../fxml/EditMenuLayout.fxml"));
		GUIApplication.setScene(new Scene(root));
	}
	
	
	@FXML
	public void quitButtonAction() throws IOException {
		GUIApplication.backScene();
	}
	
	
	
	
	
	

}
