package leveleditor;

import java.awt.event.*;
import java.util.ArrayList;
import javax.swing.*;
import static leveleditor.Globals.*;

public class OpenWindow extends JFrame {

    public final DefaultListModel mainListModel = new DefaultListModel();
    public final JList mainList = new JList(mainListModel);

    public OpenWindow() {
        mainList.setSelectionMode(ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);
        mainList.setVisibleRowCount(20);
        mainList.setPrototypeCellValue("                                                                     ");
        JScrollPane mainScrollPane = new JScrollPane(mainList);
        mainList.addKeyListener(new KeyListener() {
            boolean ENTERisDown = false, DELETEisDown = false, CTRNisDown = false, CTRRisDown = false;

            @Override
            public void keyTyped(KeyEvent ke) {
            }

            @Override
            public void keyPressed(KeyEvent ke) {
                int key = ke.getKeyCode();
                if (key == KeyEvent.VK_ENTER) {
                    ENTERisDown = true;
                }
            }

            @Override
            public void keyReleased(KeyEvent ke) {
                int key = ke.getKeyCode();
                if (key == KeyEvent.VK_ENTER && ENTERisDown) {
                    open();
                    ENTERisDown = false;
                }
            }
        });
        mainScrollPane.setWheelScrollingEnabled(true);
        setTitle("Open");
        JPanel mainPanel = new JPanel();
        JButton mainAddButton = new JButton("Open");
        mainAddButton.setFocusable(false);
        add(mainPanel);
        mainPanel.add(mainScrollPane);
        mainPanel.add(mainAddButton);
        mainAddButton.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent ae) {
                open();
            }
        });
        pack();
        setLocationRelativeTo(null);
        setResizable(false);
    }

    public final void display(ArrayList<World> worlds) {
        refreshMainFrame(worlds);
        setVisible(true);
    }

    public final void open() {
        int[] selected = mainList.getSelectedIndices();
        for (int i = 0; i < selected.length; i++) {
            for (int j = 0; j < worlds.size(); j++) {
                if (worlds.get(j).getName() == mainListModel.get(selected[i])) {
                    worlds.get(j).setOpen(true);
                    numberOfWorldsOpen++;
                    currentWorld = j;
                    drawOpen = true;
                    setVisible(false);
                    break;
                }
            }
        }
    }

    private void refreshMainFrame(ArrayList<World> worlds) {
        mainListModel.clear();
        for (World world : worlds) {
            if (!world.isOpen()) {
                mainListModel.addElement(world.getName());
            }
        }
        if (!mainListModel.isEmpty()) {
            mainList.setSelectedIndex(0);
        }
    }
}
