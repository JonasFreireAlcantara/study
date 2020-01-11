package gui.controller;

import bean.Debtor;
import business.SystemFacade;
import gui.GUIApplication;
import javafx.collections.FXCollections;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.MouseEvent;
import javafx.scene.control.TableColumn;

public class InformationsDebtorController {
	
	private SystemFacade system = SystemFacade.getInstance();

	@FXML
	private Label debtorNameLabel;
	@FXML
	private Label totalPerMonthLabel;
	@FXML
	private Label totalLabel;
	@FXML
	private Label amountPurchaseLabel;

	@FXML
	private TableView<Debtor> debtorTableView;
	@FXML
	private TableColumn<Debtor, String> debtorNameTableColumn;
	
	@FXML
	private Button backButton;
	
	
	@FXML
	private void initialize() {
		GUIApplication.setTitle("Informações Devedor");
		
		debtorTableView.setItems( FXCollections.observableArrayList(system.debtorsGetDebtors()) );
		debtorNameTableColumn.setCellValueFactory( new PropertyValueFactory<Debtor, String>("name"));
		
		debtorTableView.setOnMouseClicked( new EventHandler<MouseEvent>() {
			
			@Override
			public void handle(MouseEvent event) {
				Debtor debtor = debtorTableView.getSelectionModel().getSelectedItem();
				
				debtorNameLabel.setText(debtor.getName());
				totalPerMonthLabel.setText( Double.toString(debtor.getTotalOfDebtPerMonth()) );
				amountPurchaseLabel.setText( Integer.toString(debtor.getAmountOfProducts()) );
				totalLabel.setText( Double.toString(debtor.getTotalOfDebt()) );
			}
			
			
		});
		
	}
	
	
	@FXML
	public void backButtonAction() {
		GUIApplication.backScene();
	}
	
	

}
