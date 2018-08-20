.PHONY: clean All

All:
	@echo "----------Building project:[ HW3_Poly - Debug ]----------"
	@cd "HW3_Poly" && "$(MAKE)" -f  "HW3_Poly.mk"
clean:
	@echo "----------Cleaning project:[ HW3_Poly - Debug ]----------"
	@cd "HW3_Poly" && "$(MAKE)" -f  "HW3_Poly.mk" clean
