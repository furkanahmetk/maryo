'''

TODO:
-Save Level butonu : Save butonuna basinca text dosyasi olarak belirtilen
	formatta dosyayi cikaracak (ters cevirmeyi unutma)
-Show butonu : 1 2 3 4 [5] sagdaki duruma gore 4 ile 5'i gosterecek
-Save Frame butonu : O anki leveli self.level'a ekleyecek [DONE]

'''

from Tkinter import *

DISPLAY_X = 32#int(raw_input("Please Enter The Level Length "))
DISPLAY_Y = 8#int(raw_input("Please Enter The Level Length "))

class LevelEditor(Frame):
	def __init__(self, master, DISPLAY_X=32, DISPLAY_Y=8):
		Frame.__init__(self, master)
		self.grid()

		self.DISPLAY_X = DISPLAY_X
		self.DISPLAY_Y = DISPLAY_Y

		self.level_x = 0
		self.level_y = DISPLAY_Y

		self.current_frame_x = 0
		self.current_frame_y = DISPLAY_Y

		self.exported_level= [
							  "",
							  "",
							  "",    
							  "",    
							  "",    
							  "",
							  "",
							  "",    
							 ]
		self.checkboxes = []
		self.level = []
		self.current_frame = []

		self.init_level()
		self.init_checkboxes()
		self.init_current_frame()
		self.init_filling_buttons()
		
		Button(self, command = self.show_current_frame, text="Show Frame").grid(row=0, column=0)
		Button(self, command = self.show_level, text="Show Level").grid(row=1, column=0)
		Button(self, command = self.save_frame, text="Save Frame").grid(row=2,column=0)
		Button(self, command = self.export_level , text="Export Level").grid(row=3,column=0)
		Button(self, text='Quit' , command = root.quit).grid(row = 4 , column = 0)
		Button(self, command = self.reset_all_states, text="X").grid(row = 0 , column = 1)
			
	def save_frame(self):
		for y in range(self.DISPLAY_Y):
			for x in range(self.DISPLAY_X):
				self.level[y].append( self.get_checkbox_state(x,y) )
		
		self.level_x += self.DISPLAY_X
	
	def get_checkbox_state(self, x, y):
		return str( int( self.checkboxes[y][x].get() ) )
	
	def show_level(self):

		#for y in range( self.level_y-1,-1,-1 ):
		for y in range( self.level_y ):
			for x in range( self.DISPLAY_X*2 , 0 , -1):
				print self.level[y][-x],
			print ""
		print ""
		
	def show_current_frame(self):
		
		for y in range(self.DISPLAY_Y):
			for x in range(self.DISPLAY_X):
				a=0-(32-x)
				self.current_frame[y].append( self.level[y][a] )
		self.current_frame_x += self.DISPLAY_X
		
		for y in range(self.DISPLAY_Y):
			for x in range(self.DISPLAY_X):
				self.current_frame[y].append( self.get_checkbox_state(x,y) )
		
		self.current_frame_x += self.DISPLAY_X
		
		#for y in range( self.level_y-1,-1,-1 ):
		for y in range ( self.current_frame_y ) :
			for x in range( self.current_frame_x ):
				print self.current_frame[y][x],
			print ""
		print ""
		
		self.current_frame_x = 0
		for y in range( len(self.current_frame) ):
			self.current_frame[y] = []
		
	def show_checkbox_states(self):
		for i in range(DISPLAY_Y):
			for j in range(DISPLAY_X):
				print int(self.checkboxes[i][j].get()),
			print ""
		print ""
			
	def is_row_empty(self, r):
		for c in range(self.DISPLAY_X):
			if self.checkboxes[r][c].get():
				return False
		return True
			
	def is_column_empty(self, c):
		for r in range(self.DISPLAY_Y):
			if self.checkboxes[r][c].get():
				return False
		return True
			
	def reset_all_states(self):
			
		for r in range(self.DISPLAY_Y):
			for c in range(self.DISPLAY_X):
				self.checkboxes[r][c].set(False)	
					
	def change_row_state(self , r):
		state = self.is_row_empty(r)
		for c in range(self.DISPLAY_X):
			self.checkboxes[r][c].set(state)
					
	def change_column_state(self , c):
		if self.is_column_empty(c):
			for r in range(self.DISPLAY_Y):
				self.checkboxes[r][c].set(True)
		else:
			for r in range(self.DISPLAY_Y):
				self.checkboxes[r][c].set(False)
	
	def init_filling_buttons(self):
		for r in range(self.DISPLAY_Y):
			Button(self, command = lambda rw=r: self.change_row_state(rw)).grid(row = 1+r , column = 1)
		for c in range(self.DISPLAY_X):
			Button(self, command = lambda clm=c: self.change_column_state(clm)).grid(row =0 , column = 2+c)
		
	def init_checkboxes(self):
		self.init_checkbox_vars()
		for r in range(self.DISPLAY_Y):
			for c in range(self.DISPLAY_X):
				Checkbutton(self, variable=self.checkboxes[r][c], text="").grid(row=1+r, column=2+c, sticky=W)
		
	def init_checkbox_vars(self):
		for i in range(self.DISPLAY_Y):
			self.checkboxes.append([])
			for j in range(self.DISPLAY_X):
				self.checkboxes[i].append(BooleanVar())
		
	def init_level(self):
		for i in xrange(DISPLAY_Y):
			self.level.append([])
		
	def init_current_frame(self):
		for i in xrange(DISPLAY_Y):
			self.current_frame.append([])
		
	def export_level(self):
		
		for y in xrange(self.level_y):
			for x in xrange(self.level_x):
				self.exported_level[y] += self.level[y][x]
			self.exported_level[y] = ",".join(self.exported_level[y])
			self.exported_level[y] += "},"
			
			
		with open("level.txt", "w") as fo:
			fo.write("#define LEVEL_Y 8\n");
			fo.write("#define LEVEL_X ");
			fo.write(str(self.level_x));
			fo.write("\n\n");
			fo.write("bool level[LEVEL_Y][LEVEL_X] =\n");
			fo.write("    {\n\n");
			for y in xrange(len(self.exported_level)):
				fo.write("    /*");
				fo.write(str(y));
				fo.write("*/{");
				fo.write(str(self.exported_level[7-y]));
				fo.write("\n")
			fo.write("    };");
		self.exported_level= [
							  "",
							  "",
							  "",    
							  "",    
							  "",    
							  "",
							  "",
							  "",    
							 ]
		
root = Tk()
root.title("Mario Level Editor")
app = LevelEditor(root)
root.mainloop()

