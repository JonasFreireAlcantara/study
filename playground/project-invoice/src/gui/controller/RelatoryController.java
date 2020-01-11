
package gui.controller;

import java.util.Calendar;

import bean.Debtor;
import business.SystemFacade;
import gui.GUIApplication;
import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TableView;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;

public class RelatoryController {
	
	private SystemFacade system = SystemFacade.getInstance();

	@FXML
	private Label dateLabel;
	
	@FXML
	private TableView<Debtor> relatoryTableView;
	@FXML
	private TableColumn<Debtor, String> debtorTableColumn;
	@FXML
	private TableColumn<Debtor, Integer> amountPurchaseTableColumn;
	@FXML
	private TableColumn<Debtor, Double> totalPerMonthTableColumn;
	
	@FXML
	private TextField totalTextField;
	
	@FXML
	private Button backButton;
	
	
	
	@FXML
	private void initialize() {
		GUIApplication.setTitle("Relatório");
		
		Calendar today = Calendar.getInstance();
		
		relatoryTableView.setItems( FXCollections.observableArrayList(system.debtorsGetDebtors()) );
		debtorTableColumn.setCellValueFactory( new PropertyValueFactory<Debtor, String>("name"));
		amountPurchaseTableColumn.setCellValueFactory( new PropertyValueFactory<Debtor, Integer>("amountOfProducts"));
		totalPerMonthTableColumn.setCellValueFactory( new PropertyValueFactory<Debtor, Double>("totalOfDebtPerMonth"));
		
		totalTextField.setDisable(true);
		totalTextField.setText( Double.toString(system.debtorTotalDebtSystemPerMonth() ));
		
		String date = today.get(Calendar.DAY_OF_MONTH) + " / " + (today.get(Calendar.MONTH) + 1) + " / " + today.get(Calendar.YEAR);
		dateLabel.setText(date);
	}
	
	
	@FXML
	public void backButtonAction() {
		GUIApplication.backScene();
	}

}
